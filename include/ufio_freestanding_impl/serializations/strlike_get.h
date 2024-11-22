#pragma once

namespace ufio
{

namespace details
{

template <bool noskipws, bool line>
inline constexpr ::ufio::manipulators::scalar_flags strlike_default_scalar_flags{.noskipws = noskipws, .line = line};

}

namespace manipulators
{

template <typename T>
struct basic_strlike_get
{
	using value_type = T;
	using manip_tag = manip_tag_t;
#ifndef __INTELLISENSE__
#if __has_cpp_attribute(msvc::no_unique_address)
	[[msvc::no_unique_address]]
#elif __has_cpp_attribute(no_unique_address)
	[[no_unique_address]]
#endif
#endif
	T reference;
};

template <typename T>
inline constexpr auto strlike_get(T &reference) noexcept
{
	return ::ufio::manipulators::scalar_manip_t<
		::ufio::details::strlike_default_scalar_flags<false, false>,
		::ufio::manipulators::basic_strlike_get<decltype(io_strlike_ref(io_alias, reference))>>{
		{io_strlike_ref(io_alias, reference)}};
}

template <typename T>
inline constexpr auto strlike_line_get(T &reference) noexcept
{
	return ::ufio::manipulators::scalar_manip_t<
		::ufio::details::strlike_default_scalar_flags<false, true>,
		::ufio::manipulators::basic_strlike_get<decltype(io_strlike_ref(io_alias, reference))>>{
		{io_strlike_ref(io_alias, reference)}};
}

template <typename T>
inline constexpr auto strlike_whole_get(T &reference) noexcept
{
	return ::ufio::manipulators::whole_get_t<
		::ufio::manipulators::basic_strlike_get<decltype(io_strlike_ref(io_alias, reference))>>{
		{io_strlike_ref(io_alias, reference)}};
}

} // namespace manipulators

namespace details
{

template <bool noskipws, bool line, bool ctxread = false, ::std::integral char_type, typename T>
inline constexpr ::ufio::parse_result<char_type const *>
scan_context_define_strlike_impl(::std::conditional_t<ctxread, bool, bool &> skip_space_done, char_type const *first,
								 char_type const *last, T ref)
{
	auto it{first};
	if constexpr (!noskipws && !line)
	{
		if (!skip_space_done)
		{
			it = ::ufio::find_none_c_space(it, last);
			if (it == last)
			{
				return {it, ::ufio::parse_code::partial};
			}
			skip_space_done = true;
			obuffer_set_curr(ref, obuffer_begin(ref));
		}
	}
	auto it_space{it};
	if constexpr (line)
	{
		it_space = ::ufio::find_lf(it_space, last);
	}
	else
	{
		it_space = ::ufio::find_c_space(it_space, last);
	}
	if constexpr (noskipws || line)
	{
		if (!skip_space_done)
		{
			obuffer_set_curr(ref, obuffer_begin(ref));
		}
		::ufio::operations::decay::write_all_decay(ref, it, it_space);
		skip_space_done = true;
	}
	else
	{
		::ufio::operations::decay::write_all_decay(ref, it, it_space);
	}
	if (it_space == last)
	{
		return {it_space, ::ufio::parse_code::partial};
	}
	if constexpr (line)
	{
		++it_space;
	}
	return {it_space, ::ufio::parse_code::ok};
}

template <bool ctxread = false, ::std::integral char_type, typename T>
inline constexpr ::ufio::parse_result<char_type const *>
scan_context_define_strlike_getall_impl(::std::conditional_t<ctxread, bool, bool &> skip_space_done,
										char_type const *first, char_type const *last, T ref)
{
	if (!skip_space_done)
	{
		obuffer_set_curr(ref, obuffer_begin(ref));
		skip_space_done = true;
	}
	::ufio::operations::decay::write_all_decay(ref, first, last);
	return {last, ::ufio::parse_code::partial};
}

inline constexpr ::ufio::parse_code scan_context_eof_strlike_define_impl(bool skip_space_done) noexcept
{
	if (skip_space_done)
	{
		return ::ufio::parse_code::ok;
	}
	else
	{
		return ::ufio::parse_code::end_of_file;
	}
}

} // namespace details

template <::std::integral char_type, ::ufio::manipulators::scalar_flags flags, typename T>
inline constexpr io_type_t<
	::std::conditional_t<(::ufio::buffer_strlike<char_type, typename ::std::remove_cvref_t<T>::value_type> &&
						  ::std::same_as<typename ::std::remove_cvref_t<T>::char_type, char_type>),
						 ::ufio::details::str_get_all_context, ::ufio::details::basic_concat_buffer<char_type>>>
scan_context_type(io_reserve_type_t<char_type, ::ufio::manipulators::scalar_manip_t<
												   flags, ::ufio::manipulators::basic_strlike_get<T>>>) noexcept
{
	return {};
}

template <::std::integral char_type, ::ufio::manipulators::scalar_flags flags, typename ctx_type, typename T>
inline constexpr parse_result<char_type const *> scan_context_define(
	io_reserve_type_t<char_type,
					  ::ufio::manipulators::scalar_manip_t<flags, ::ufio::manipulators::basic_strlike_get<T>>>,
	ctx_type &ctx, char_type const *first, char_type const *last,
	::ufio::manipulators::scalar_manip_t<flags, ::ufio::manipulators::basic_strlike_get<T>> ref)
{
	using value_type = ::std::remove_cvref_t<T>;
	using undefttype_char_type = typename ::std::remove_cvref_t<value_type>::char_type;
	if constexpr (::ufio::buffer_strlike<char_type, typename ::std::remove_cvref_t<T>::value_type> &&
				  ::std::same_as<undefttype_char_type, char_type>)
	{
		return ::ufio::details::scan_context_define_strlike_impl<flags.noskipws, flags.line>(
			ctx.copying, first, last, ref.reference.reference);
	}
	else
	{
		bool b{ctx.buffer_begin != ctx.buffer_curr};
		auto [it, ec] = ::ufio::details::scan_context_define_strlike_impl<flags.noskipws, flags.line, true>(
			b, first, last, io_strlike_ref(io_alias, ctx));
		if (ec == ::ufio::parse_code::ok)
		{
			using ioreftype = typename value_type::value_type;
			if constexpr (::std::same_as<undefttype_char_type, char_type>)
			{
				*ref.reference.reference.ptr = strlike_construct_define(
					io_strlike_type<undefttype_char_type, ioreftype>, ctx.buffer_begin, ctx.buffer_curr);
			}
			else
			{
				*ref.reference.reference.ptr = ::ufio::basic_general_concat<false, undefttype_char_type, ioreftype>(
					::ufio::manipulators::code_cvt(
						::ufio::manipulators::strvw(ctx.buffer_begin, ctx.buffer_curr)));
			}
		}
		return {it, ec};
	}
}

template <::ufio::manipulators::scalar_flags flags, ::std::integral char_type, typename ctx_type, typename T>
inline constexpr ::ufio::parse_code scan_context_eof_define(
	io_reserve_type_t<char_type,
					  ::ufio::manipulators::scalar_manip_t<flags, ::ufio::manipulators::basic_strlike_get<T>>>,
	ctx_type &ctx, ::ufio::manipulators::scalar_manip_t<flags, ::ufio::manipulators::basic_strlike_get<T>> ref)
{
	using value_type = ::std::remove_cvref_t<T>;
	using undefttype_char_type = typename ::std::remove_cvref_t<value_type>::char_type;
	if constexpr (flags.line || flags.noskipws)
	{
		if constexpr (::ufio::buffer_strlike<char_type, typename ::std::remove_cvref_t<T>::value_type> &&
					  ::std::same_as<undefttype_char_type, char_type>)
		{
			if (obuffer_begin(ref.reference.reference) == obuffer_curr(ref.reference.reference))
			{
				return ::ufio::parse_code::end_of_file;
			}
			else
			{
				return ::ufio::parse_code::ok;
			}
		}
		else
		{
			if (ctx.buffer_begin == ctx.buffer_curr)
			{
				return ::ufio::parse_code::end_of_file;
			}
			else
			{
				using ioreftype = typename value_type::value_type;
				if constexpr (::std::same_as<undefttype_char_type, char_type>)
				{
					*ref.reference.reference.ptr = strlike_construct_define(
						io_strlike_type<undefttype_char_type, ioreftype>, ctx.buffer_begin, ctx.buffer_curr);
				}
				else
				{
					*ref.reference.reference.ptr =
						::ufio::basic_general_concat<false, undefttype_char_type, ioreftype>(
							::ufio::manipulators::code_cvt(
								::ufio::manipulators::strvw(ctx.buffer_begin, ctx.buffer_curr)));
				}
				return ::ufio::parse_code::ok;
			}
		}
	}
	else
	{
		if constexpr (::ufio::buffer_strlike<char_type, typename ::std::remove_cvref_t<T>::value_type> &&
					  ::std::same_as<undefttype_char_type, char_type>)
		{
			return ::ufio::details::scan_context_eof_strlike_define_impl(ctx.copying);
		}
		else
		{
			if (ctx.buffer_begin != ctx.buffer_curr)
			{
				using ioreftype = typename value_type::value_type;
				if constexpr (::std::same_as<undefttype_char_type, char_type>)
				{
					*ref.reference.reference.ptr = strlike_construct_define(
						io_strlike_type<undefttype_char_type, ioreftype>, ctx.buffer_begin, ctx.buffer_curr);
				}
				else
				{
					*ref.reference.reference.ptr =
						::ufio::basic_general_concat<false, undefttype_char_type, ioreftype>(
							::ufio::manipulators::code_cvt(
								::ufio::manipulators::strvw(ctx.buffer_begin, ctx.buffer_curr)));
				}
				return ::ufio::parse_code::ok;
			}
			else
			{
				return ::ufio::parse_code::end_of_file;
			}
		}
	}
}

template <::std::integral char_type, typename T>
inline constexpr io_type_t<
	::std::conditional_t<(::ufio::buffer_strlike<char_type, typename ::std::remove_cvref_t<T>::value_type> &&
						  ::std::same_as<typename ::std::remove_cvref_t<T>::char_type, char_type>),
						 ::ufio::details::str_get_all_context, ::ufio::details::basic_concat_buffer<char_type>>>
scan_context_type(
	io_reserve_type_t<char_type,
					  ::ufio::manipulators::whole_get_t<::ufio::manipulators::basic_strlike_get<T>>>) noexcept
{
	return {};
}

template <::std::integral char_type, typename ctx_type, typename T>
inline constexpr parse_result<char_type const *> scan_context_define(
	io_reserve_type_t<char_type, ::ufio::manipulators::whole_get_t<::ufio::manipulators::basic_strlike_get<T>>>,
	ctx_type &ctx, char_type const *first, char_type const *last,
	::ufio::manipulators::whole_get_t<::ufio::manipulators::basic_strlike_get<T>> ref)
{
	using value_type = ::std::remove_cvref_t<T>;
	using undefttype_char_type = typename ::std::remove_cvref_t<value_type>::char_type;
	if constexpr (::ufio::buffer_strlike<char_type, typename ::std::remove_cvref_t<T>::value_type> &&
				  ::std::same_as<undefttype_char_type, char_type>)
	{
		return ::ufio::details::scan_context_define_strlike_getall_impl(ctx.copying, first, last,
																		   ref.reference.reference);
	}
	else
	{
		bool b{ctx.buffer_begin != ctx.buffer_curr};
		auto [it, ec] = ::ufio::details::scan_context_define_strlike_getall_impl<true>(
			b, first, last, io_strlike_ref(io_alias, ctx));
		if (ec == ::ufio::parse_code::ok)
		{
			using ioreftype = typename value_type::value_type;
			if constexpr (::std::same_as<undefttype_char_type, char_type>)
			{
				*ref.reference.reference.ptr = strlike_construct_define(
					io_strlike_type<undefttype_char_type, ioreftype>, ctx.buffer_begin, ctx.buffer_curr);
			}
			else
			{
				*ref.reference.reference.ptr = ::ufio::basic_general_concat<false, undefttype_char_type, ioreftype>(
					::ufio::manipulators::code_cvt(
						::ufio::manipulators::strvw(ctx.buffer_begin, ctx.buffer_curr)));
			}
		}
		return {it, ec};
	}
}

template <::std::integral char_type, typename ctx_type, typename T>
inline constexpr ::ufio::parse_code scan_context_eof_define(
	io_reserve_type_t<char_type, ::ufio::manipulators::whole_get_t<::ufio::manipulators::basic_strlike_get<T>>>,
	ctx_type &ctx, ::ufio::manipulators::whole_get_t<::ufio::manipulators::basic_strlike_get<T>> ref)
{

	using value_type = ::std::remove_cvref_t<T>;
	using undefttype_char_type = typename ::std::remove_cvref_t<value_type>::char_type;
	if constexpr (::ufio::buffer_strlike<char_type, typename ::std::remove_cvref_t<T>::value_type> &&
				  ::std::same_as<undefttype_char_type, char_type>)
	{
		if (!ctx.copying)
		{
			obuffer_set_curr(ref.reference.reference, obuffer_begin(ref.reference.reference));
		}
	}
	else
	{
		using ioreftype = typename value_type::value_type;
		if constexpr (::std::same_as<undefttype_char_type, char_type>)
		{
			*ref.reference.reference.ptr = strlike_construct_define(io_strlike_type<undefttype_char_type, ioreftype>,
																	ctx.buffer_begin, ctx.buffer_curr);
		}
		else
		{
			*ref.reference.reference.ptr = ::ufio::basic_general_concat<false, undefttype_char_type, ioreftype>(
				::ufio::manipulators::code_cvt(::ufio::manipulators::strvw(ctx.buffer_begin, ctx.buffer_curr)));
		}
	}
	return ::ufio::parse_code::ok;
}

} // namespace ufio
