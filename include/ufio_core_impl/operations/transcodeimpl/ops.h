#pragma once

namespace ufio
{

namespace operations::decay
{

template <typename T>
	requires(::ufio::operations::decay::defines::has_transcode_bytes_min_tosize_decay_define<T> ||
			 ::ufio::operations::decay::defines::has_transcode_min_tosize_decay_define<T> ||
			 ::ufio::operations::decay::defines::has_transcode_bytes_imaginary_decay_define<T> ||
			 ::ufio::operations::decay::defines::has_transcode_imaginary_decay_define<T>)
inline constexpr ::std::size_t transcode_bytes_min_tosize_decay(::ufio::transcode_reserve_t<T>) noexcept
{
	if constexpr (::ufio::operations::decay::defines::has_transcode_bytes_min_tosize_decay_define<T>)
	{
		return transcode_bytes_min_tosize_decay_define(::ufio::transcode_reserve<T>);
	}
	else if constexpr (::ufio::operations::decay::defines::has_transcode_min_tosize_decay_define<T>)
	{
		return transcode_min_tosize_decay_define(::ufio::transcode_reserve<T>) * sizeof(typename T::to_value_type);
	}
	else if constexpr (::ufio::operations::decay::defines::has_transcode_bytes_imaginary_decay_define<T>)
	{
		return 1;
	}
	else if constexpr (::ufio::operations::decay::defines::has_transcode_imaginary_decay_define<T>)
	{
		return sizeof(typename T::to_value_type);
	}
}

template <typename T>
	requires(::ufio::operations::decay::defines::has_transcode_bytes_tosize_decay_define<T> ||
			 ::ufio::operations::decay::defines::has_transcode_tosize_decay_define<T> ||
			 ::ufio::operations::decay::defines::has_transcode_bytes_imaginary_decay_define<T> ||
			 ::ufio::operations::decay::defines::has_transcode_imaginary_decay_define<T>)
inline constexpr ::std::size_t transcode_bytes_imaginary_decay(T t,
															   ::std::byte const *fromfirst, ::std::byte const *fromlast, ::std::size_t mxsz);

template <typename T>
	requires(::ufio::operations::decay::defines::has_transcode_bytes_tosize_decay_define<T> ||
			 ::ufio::operations::decay::defines::has_transcode_tosize_decay_define<T> ||
			 ::ufio::operations::decay::defines::has_transcode_bytes_imaginary_decay_define<T> ||
			 ::ufio::operations::decay::defines::has_transcode_imaginary_decay_define<T>)
inline constexpr ::std::size_t transcode_bytes_tosize_decay(T t,
															::std::byte const *fromfirst, ::std::byte const *fromlast)
{
	if constexpr (::ufio::operations::decay::defines::has_transcode_bytes_tosize_decay_define<T>)
	{
		return transcode_bytes_tosize_decay_define(t, fromfirst, fromlast);
	}
	else if constexpr (::ufio::operations::decay::defines::has_transcode_tosize_decay_define<T>)
	{
		using from_value_type = typename T::from_value_type;
		using to_value_type = typename T::to_value_type;
		using from_may_alias_const_ptr
#if __has_cpp_attribute(__gnu__::__may_alias__)
			[[__gnu__::__may_alias__]]
#endif
			= from_value_type const *;
		return transcode_tosize_decay_define(t, reinterpret_cast<from_may_alias_const_ptr>(fromfirst),
											 reinterpret_cast<from_may_alias_const_ptr>(fromfirst) + static_cast<::std::size_t>(fromlast - fromfirst) / sizeof(from_value_type)) *
			   sizeof(to_value_type);
	}
	else if constexpr (::ufio::operations::decay::defines::has_transcode_bytes_imaginary_decay_define<T> ||
					   ::ufio::operations::decay::defines::has_transcode_imaginary_decay_define<T>)
	{
		constexpr ::std::size_t bfminsz{::ufio::operations::decay::transcode_bytes_min_tosize_decay(::ufio::transcode_reserve<T>)};
		constexpr ::std::size_t mxsz{::std::numeric_limits<::std::size_t>::max() / 2};
		for (::std::size_t n{bfminsz};;)
		{
			if (::ufio::operations::decay::transcode_bytes_imaginary_decay(t, fromfirst, fromlast, n) == fromlast)
			{
				return n;
			}
			if (mxsz < n) [[unlikely]]
			{
				::ufio::fast_terminate();
			}
			n <<= 1;
		}
#if __has_cpp_attribute(unreachable)
		[[unreachable]];
#endif
	}
}

template <typename T>
	requires(::ufio::operations::decay::defines::has_transcode_bytes_tosize_decay_define<T> ||
			 ::ufio::operations::decay::defines::has_transcode_tosize_decay_define<T> ||
			 ::ufio::operations::decay::defines::has_transcode_bytes_imaginary_decay_define<T> ||
			 ::ufio::operations::decay::defines::has_transcode_imaginary_decay_define<T>)
inline constexpr ::std::byte const *transcode_bytes_imaginary_decay(T t,
																	::std::byte const *fromfirst, ::std::byte const *fromlast, ::std::size_t mxsz)
{
	if constexpr (::ufio::operations::decay::defines::has_transcode_bytes_imaginary_decay_define<T>)
	{
		return transcode_bytes_imaginary_decay_define(t, fromfirst, fromlast, mxsz);
	}
	else if constexpr (::ufio::operations::decay::defines::has_transcode_imaginary_decay_define<T>)
	{
		using from_value_type = typename T::from_value_type;
		using from_may_alias_const_ptr
#if __has_cpp_attribute(__gnu__::__may_alias__)
			[[__gnu__::__may_alias__]]
#endif
			= from_value_type const *;
		return reinterpret_cast<::std::byte const *>(transcode_imaginary_decay_define(t, reinterpret_cast<from_may_alias_const_ptr>(fromfirst),
																					  reinterpret_cast<from_may_alias_const_ptr>(fromfirst) + static_cast<::std::size_t>(fromlast - fromfirst) / sizeof(typename T::from_value_type), mxsz));
	}
	else
	{
		::std::size_t n{static_cast<::std::size_t>(fromlast - fromfirst)};
		for (; (n && ::ufio::operations::decay::transcode_bytes_tosize_decay(t, fromfirst, fromfirst + n) <= mxsz); n >>= 1u)
		{
		}
		return fromfirst + n;
	}
}

template <typename T>
	requires(::ufio::operations::decay::defines::has_transcode_bytes_decay_define<T> ||
			 ::ufio::operations::decay::defines::has_transcode_decay_define<T>)
inline constexpr ::ufio::transcode_bytes_result transcode_bytes_decay(T t,
																		 ::std::byte const *fromfirst, ::std::byte const *fromlast,
																		 ::std::byte *tofirst, ::std::byte *tolast)
{
	if constexpr (::ufio::operations::decay::defines::has_transcode_bytes_decay_define<T>)
	{
		return transcode_bytes_decay_define(t, fromfirst, fromlast, tofirst, tolast);
	}
	else
	{
		using from_value_type = typename T::from_value_type;
		using to_value_type = typename T::to_value_type;
		using from_may_alias_const_ptr
#if __has_cpp_attribute(__gnu__::__may_alias__)
			[[__gnu__::__may_alias__]]
#endif
			= from_value_type const *;
		using to_may_alias_ptr
#if __has_cpp_attribute(__gnu__::__may_alias__)
			[[__gnu__::__may_alias__]]
#endif
			= to_value_type *;
		auto [fromit, toit] = transcode_decay_define(t, reinterpret_cast<from_may_alias_const_ptr>(fromfirst),
													 reinterpret_cast<from_may_alias_const_ptr>(fromfirst) + static_cast<::std::size_t>(fromlast - fromfirst) / sizeof(from_value_type),
													 reinterpret_cast<to_may_alias_ptr>(tofirst),
													 reinterpret_cast<to_may_alias_ptr>(tofirst) + static_cast<::std::size_t>(tolast - tofirst) / sizeof(to_value_type));
		return {reinterpret_cast<::std::byte const *>(fromit), reinterpret_cast<::std::byte *>(toit)};
	}
}

template <typename T>
	requires((sizeof(typename T::from_value_type) == 1 && sizeof(typename T::to_value_type) == 1 && (::ufio::operations::decay::defines::has_transcode_bytes_min_tosize_decay_define<T> || ::ufio::operations::decay::defines::has_transcode_bytes_imaginary_decay_define<T>)) ||
			 ::ufio::operations::decay::defines::has_transcode_min_tosize_decay_define<T> ||
			 ::ufio::operations::decay::defines::has_transcode_imaginary_decay_define<T>)
inline constexpr ::std::size_t transcode_min_tosize_decay(::ufio::transcode_reserve_t<T>) noexcept
{
	if constexpr (::ufio::operations::decay::defines::has_transcode_min_tosize_decay_define<T>)
	{
		return transcode_min_tosize_decay_define(::ufio::transcode_reserve<T>);
	}
	else if constexpr (::ufio::operations::decay::defines::has_transcode_bytes_min_tosize_decay_define<T> &&
					   sizeof(typename T::from_value_type) == 1 && sizeof(typename T::to_value_type) == 1)
	{
		return transcode_bytes_min_tosize_decay_define(::ufio::transcode_reserve<T>);
	}
	else
	{
		return 1;
	}
}

template <typename T>
	requires(::ufio::operations::decay::defines::has_transcode_bytes_decay_define<T> ||
			 (::ufio::operations::decay::defines::has_transcode_decay_define<T> &&
			  sizeof(typename T::from_value_type) == 1 && sizeof(typename T::to_value_type) == 1))
inline constexpr ::ufio::transcode_bytes_result transcode_decay(T t,
																   typename T::from_value_type const *fromfirst, typename T::from_value_type const *fromlast,
																   typename T::to_value_type *tofirst, typename T::to_value_type *tolast)
{
	if constexpr (::ufio::operations::decay::defines::has_transcode_decay_define<T>)
	{
		return transcode_decay_define(t, fromfirst, fromlast, tofirst, tolast);
	}
	else if constexpr (::ufio::operations::decay::defines::has_transcode_bytes_decay_define<T>)
	{
		return transcode_bytes_decay_define(t, fromfirst, fromlast, tofirst, tolast);
	}
}

template <typename T>
	requires(((::ufio::operations::decay::defines::has_transcode_bytes_tosize_decay_define<T> ||
			   ::ufio::operations::decay::defines::has_transcode_tosize_decay_define<T>) &&
			  (sizeof(typename T::from_value_type) == 1 && sizeof(typename T::to_value_type) == 1)) ||
			 ::ufio::operations::decay::defines::has_transcode_bytes_imaginary_decay_define<T> ||
			 ::ufio::operations::decay::defines::has_transcode_imaginary_decay_define<T>)
inline constexpr ::std::size_t transcode_imaginary_decay(T t,
														 typename T::from_value_type const *fromfirst, typename T::from_value_type const *fromlast);

template <typename T>
	requires(((::ufio::operations::decay::defines::has_transcode_bytes_tosize_decay_define<T> ||
			   ::ufio::operations::decay::defines::has_transcode_tosize_decay_define<T>) &&
			  (sizeof(typename T::from_value_type) == 1 && sizeof(typename T::to_value_type) == 1)) ||
			 ::ufio::operations::decay::defines::has_transcode_bytes_imaginary_decay_define<T> ||
			 ::ufio::operations::decay::defines::has_transcode_imaginary_decay_define<T>)
inline constexpr ::std::size_t transcode_tosize_decay(T t,
													  typename T::from_value_type const *fromfirst, typename T::from_value_type const *fromlast)
{
	if constexpr (::ufio::operations::decay::defines::has_transcode_tosize_decay_define<T>)
	{
		::std::size_t res{transcode_tosize_decay_define(t, fromfirst, fromlast)};
		if constexpr (1 < sizeof(typename T::value_type))
		{
			constexpr ::std::size_t mxsz{::std::numeric_limits<::std::size_t>::max() / sizeof(typename T::to_value_type)};
			if (mxsz < res) [[unlikely]]
			{
				::ufio::fast_terminate();
			}
		}
		return res;
	}
	else if constexpr (::ufio::operations::decay::defines::has_transcode_bytes_tosize_decay_define<T> &&
					   (sizeof(typename T::from_value_type) == 1 && sizeof(typename T::to_value_type) == 1))
	{
		using from_value_type = typename T::from_value_type;
		using from_may_alias_const_ptr
#if __has_cpp_attribute(__gnu__::__may_alias__)
			[[__gnu__::__may_alias__]]
#endif
			= from_value_type const *;
		return transcode_bytes_tosize_decay_define(t, reinterpret_cast<from_may_alias_const_ptr>(fromfirst),
												   reinterpret_cast<from_may_alias_const_ptr>(fromlast));
	}
	else if constexpr ((::ufio::operations::decay::defines::has_transcode_bytes_imaginary_decay_define<T> &&
						(sizeof(typename T::from_value_type) == 1 && sizeof(typename T::to_value_type) == 1)) ||
					   ::ufio::operations::decay::defines::has_transcode_imaginary_decay_define<T>)
	{
		constexpr ::std::size_t bfminsz{::ufio::operations::decay::transcode_min_tosize_decay(::ufio::transcode_reserve<T>)};
		constexpr ::std::size_t mxsz{::std::numeric_limits<::std::size_t>::max() / 2 / sizeof(typename T::to_value_type)};
		for (::std::size_t n{bfminsz};;)
		{
			if (::ufio::operations::decay::transcode_imaginary_decay(t, fromfirst, fromlast, n) == fromlast)
			{
				return n;
			}
			if (mxsz < n) [[unlikely]]
			{
				::ufio::fast_terminate();
			}
			n <<= 1;
		}
#if __has_cpp_attribute(unreachable)
		[[unreachable]];
#endif
	}
}

template <typename T>
	requires(((::ufio::operations::decay::defines::has_transcode_bytes_tosize_decay_define<T> ||
			   ::ufio::operations::decay::defines::has_transcode_tosize_decay_define<T>) &&
			  (sizeof(typename T::from_value_type) == 1 && sizeof(typename T::to_value_type) == 1)) ||
			 ::ufio::operations::decay::defines::has_transcode_bytes_imaginary_decay_define<T> ||
			 ::ufio::operations::decay::defines::has_transcode_imaginary_decay_define<T>)
inline constexpr typename T::from_value_type const *transcode_imaginary_decay(T t,
																			  typename T::from_value_type const *fromfirst, typename T::from_value_type const *fromlast, ::std::size_t mxsz)
{
	if constexpr (::ufio::operations::decay::defines::has_transcode_imaginary_decay_define<T>)
	{
		return transcode_imaginary_decay_define(t, fromfirst, fromlast, mxsz);
	}
	else if constexpr (::ufio::operations::decay::defines::has_transcode_bytes_imaginary_decay_define<T>)
	{
		using from_value_type = typename T::from_value_type;
		using from_may_alias_const_ptr
#if __has_cpp_attribute(__gnu__::__may_alias__)
			[[__gnu__::__may_alias__]]
#endif
			= from_value_type const *;
		return reinterpret_cast<::std::byte const *>(transcode_bytes_imaginary_decay_define(t, reinterpret_cast<from_may_alias_const_ptr>(fromfirst),
																							reinterpret_cast<from_may_alias_const_ptr>(fromfirst) + static_cast<::std::size_t>(fromlast - fromfirst) / sizeof(typename T::from_value_type), mxsz));
	}
	else
	{
		::std::size_t n{static_cast<::std::size_t>(fromlast - fromfirst)};
		for (; (n && ::ufio::operations::decay::transcode_tosize_decay(t, fromfirst, fromfirst + n) <= mxsz); n >>= 1u)
		{
		}
		return fromfirst + n;
	}
}

} // namespace operations::decay

} // namespace ufio