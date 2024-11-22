#pragma once

#pragma once

namespace ufio
{

namespace operations::decay
{

namespace defines
{

template <typename T, typename P>
concept has_output_stream_transcode_deco_filter_define =
	requires(T t, P p) { output_stream_transcode_deco_filter_define(t, p); };

template <typename T, typename P>
concept has_input_stream_transcode_deco_filter_define =
	requires(T t, P p) { input_stream_transcode_deco_filter_define(t, p); };

template <typename T, typename P>
concept has_io_stream_transcode_deco_filter_define =
	requires(T t, P p) { io_stream_transcode_deco_filter_define(t, p); };

template <typename T, typename P>
concept has_output_or_io_stream_transcode_deco_filter_define =
	has_output_stream_transcode_deco_filter_define<T, P> || has_io_stream_transcode_deco_filter_define<T, P>;

template <typename T, typename P>
concept has_input_or_io_stream_transcode_deco_filter_define =
	has_input_stream_transcode_deco_filter_define<T, P> || has_io_stream_transcode_deco_filter_define<T, P>;

} // namespace defines

template <typename T, typename D, typename... Args>
	requires(::ufio::operations::decay::defines::has_input_or_io_stream_transcode_deco_filter_define<T, D>)
#if __has_cpp_attribute(nodiscard)
[[nodiscard]]
#endif
inline constexpr auto transcode_input_decos_decay(T t, D &&deco, Args &&...args)
{
	if constexpr (::ufio::operations::decay::defines::has_input_stream_transcode_deco_filter_define<T, D>)
	{
		if constexpr (sizeof...(Args) == 0)
		{
			return input_stream_transcode_deco_filter_define(t, ::ufio::freestanding::forward<D>(deco));
		}
		else
		{
			auto newdecof{input_stream_transcode_deco_filter_define(t, ::ufio::freestanding::forward<D>(deco))};
			::ufio::operations::decay::add_input_decos_decay(
				::ufio::operations::input_stream_deco_filter_ref(newdecof),
				::ufio::freestanding::forward<Args>(args)...);
			return newdecof;
		}
	}
	else
	{
		if constexpr (sizeof...(Args) == 0)
		{
			return io_stream_transcode_deco_filter_define(t, ::ufio::freestanding::forward<D>(deco));
		}
		else
		{
			auto newdecof{io_stream_transcode_deco_filter_define(t, ::ufio::freestanding::forward<D>(deco))};
			::ufio::operations::decay::add_input_decos_decay(
				::ufio::operations::input_stream_deco_filter_ref(newdecof),
				::ufio::freestanding::forward<Args>(args)...);
			return newdecof;
		}
	}
}

template <typename T, typename D, typename... Args>
	requires(::ufio::operations::decay::defines::has_output_or_io_stream_transcode_deco_filter_define<T, D>)
#if __has_cpp_attribute(nodiscard)
[[nodiscard]]
#endif
inline constexpr auto transcode_output_decos_decay(T t, D &&deco, Args &&...args)
{
	if constexpr (::ufio::operations::decay::defines::has_output_stream_transcode_deco_filter_define<T, D>)
	{
		if constexpr (sizeof...(Args) == 0)
		{
			return output_stream_transcode_deco_filter_define(t, ::ufio::freestanding::forward<D>(deco));
		}
		else
		{
			auto newdecof{output_stream_transcode_deco_filter_define(t, ::ufio::freestanding::forward<D>(deco))};
			::ufio::operations::decay::add_output_decos_decay(
				::ufio::operations::output_stream_deco_filter_ref(newdecof),
				::ufio::freestanding::forward<Args>(args)...);
			return newdecof;
		}
	}
	else
	{
		if constexpr (sizeof...(Args) == 0)
		{
			return io_stream_transcode_deco_filter_define(t, ::ufio::freestanding::forward<D>(deco));
		}
		else
		{
			auto newdecof{io_stream_transcode_deco_filter_define(t, ::ufio::freestanding::forward<D>(deco))};
			::ufio::operations::decay::add_output_decos_decay(
				::ufio::operations::output_stream_deco_filter_ref(newdecof),
				::ufio::freestanding::forward<Args>(args)...);
			return newdecof;
		}
	}
}

template <typename T, typename D, typename... Args>
	requires(::ufio::operations::decay::defines::has_io_stream_transcode_deco_filter_define<T, D>)
#if __has_cpp_attribute(nodiscard)
[[nodiscard]]
#endif
inline constexpr auto transcode_io_decos_decay(T t, D &&deco, Args &&...args)
{
	if constexpr (sizeof...(Args) == 0)
	{
		return io_stream_transcode_deco_filter_define(t, ::ufio::freestanding::forward<D>(deco));
	}
	else
	{
		auto newdecof{io_stream_transcode_deco_filter_define(t, ::ufio::freestanding::forward<D>(deco))};
		::ufio::operations::decay::add_io_decos_decay(::ufio::operations::io_stream_deco_filter_ref(newdecof),
														 ::ufio::freestanding::forward<Args>(args)...);
		return newdecof;
	}
}

} // namespace operations::decay

namespace operations
{

namespace defines
{

template <typename T>
concept has_input_stream_transcode_deco_filter_ref_define =
	requires(T &&t) { input_stream_transcode_deco_filter_ref_define(::ufio::freestanding::forward<T>(t)); };

template <typename T>
concept has_output_stream_transcode_deco_filter_ref_define =
	requires(T &&t) { output_stream_transcode_deco_filter_ref_define(::ufio::freestanding::forward<T>(t)); };

template <typename T>
concept has_io_stream_transcode_deco_filter_ref_define =
	requires(T &&t) { io_stream_transcode_deco_filter_ref_define(::ufio::freestanding::forward<T>(t)); };

template <typename T>
concept has_input_or_io_stream_transcode_deco_filter_ref_define =
	has_input_stream_transcode_deco_filter_ref_define<T> || has_io_stream_transcode_deco_filter_ref_define<T>;

template <typename T>
concept has_output_or_io_stream_transcode_deco_filter_ref_define =
	has_output_stream_transcode_deco_filter_ref_define<T> || has_io_stream_transcode_deco_filter_ref_define<T>;

} // namespace defines

template <typename T>
	requires(::ufio::operations::defines::has_input_or_io_stream_transcode_deco_filter_ref_define<T>)
#if __has_cpp_attribute(__gnu__::__always_inline__)
[[__gnu__::__always_inline__]]
#elif __has_cpp_attribute(msvc::forceinline)
[[msvc::forceinline]]
#endif
#if __has_cpp_attribute(nodiscard)
[[nodiscard]]
#endif
inline constexpr decltype(auto) input_stream_transcode_deco_filter_ref(T &&t)
{
	if constexpr (::ufio::operations::defines::has_input_or_io_stream_transcode_deco_filter_ref_define<T>)
	{
		return input_stream_transcode_deco_filter_ref_define(::ufio::freestanding::forward<T>(t));
	}
	else
	{
		return io_transcode_deco_filter_ref_define(::ufio::freestanding::forward<T>(t));
	}
}

template <typename T>
	requires(::ufio::operations::defines::has_output_or_io_stream_transcode_deco_filter_ref_define<T>)
#if __has_cpp_attribute(__gnu__::__always_inline__)
[[__gnu__::__always_inline__]]
#elif __has_cpp_attribute(msvc::forceinline)
[[msvc::forceinline]]
#endif
#if __has_cpp_attribute(nodiscard)
[[nodiscard]]
#endif
inline constexpr decltype(auto) output_stream_transcode_deco_filter_ref(T &&t)
{
	if constexpr (::ufio::operations::defines::has_output_or_io_stream_transcode_deco_filter_ref_define<T>)
	{
		return output_stream_transcode_deco_filter_ref_define(::ufio::freestanding::forward<T>(t));
	}
	else
	{
		return io_deco_transcode_filter_ref_define(::ufio::freestanding::forward<T>(t));
	}
}

template <typename T>
	requires(::ufio::operations::defines::has_io_stream_transcode_deco_filter_ref_define<T>)
#if __has_cpp_attribute(__gnu__::__always_inline__)
[[__gnu__::__always_inline__]]
#elif __has_cpp_attribute(msvc::forceinline)
[[msvc::forceinline]]
#endif
#if __has_cpp_attribute(nodiscard)
[[nodiscard]]
#endif
inline constexpr decltype(auto) io_stream_transcode_deco_filter_ref(T &&t)
{
	return io_stream_transcode_deco_filter_ref_define(::ufio::freestanding::forward<T>(t));
}

template <typename T, typename Deco, typename... Args>
	requires(!::std::is_lvalue_reference_v<T>)
#if __has_cpp_attribute(__gnu__::__always_inline__)
[[__gnu__::__always_inline__]]
#elif __has_cpp_attribute(msvc::forceinline)
[[msvc::forceinline]]
#endif
#if __has_cpp_attribute(nodiscard)
[[nodiscard]]
#endif
inline constexpr auto transcode_input_decos(T &&t, Deco &&d, Args &&...args)
{
	return ::ufio::operations::decay::transcode_input_decos_decay(
		::ufio::operations::input_stream_transcode_deco_filter_ref(::ufio::freestanding::forward<T>(t)),
		::ufio::freestanding::forward<Deco>(d), ::ufio::freestanding::forward<Args>(args)...);
}

template <typename T, typename Deco, typename... Args>
	requires(!::std::is_lvalue_reference_v<T>)
#if __has_cpp_attribute(__gnu__::__always_inline__)
[[__gnu__::__always_inline__]]
#elif __has_cpp_attribute(msvc::forceinline)
[[msvc::forceinline]]
#endif
#if __has_cpp_attribute(nodiscard)
[[nodiscard]]
#endif
inline constexpr auto transcode_output_decos(T &&t, Deco &&d, Args &&...args)
{
	return ::ufio::operations::decay::transcode_output_decos_decay(
		::ufio::operations::output_stream_transcode_deco_filter_ref(::ufio::freestanding::forward<T>(t)),
		::ufio::freestanding::forward<Deco>(d), ::ufio::freestanding::forward<Args>(args)...);
}

template <typename T, typename Deco, typename... Args>
	requires(!::std::is_lvalue_reference_v<T>)
#if __has_cpp_attribute(__gnu__::__always_inline__)
[[__gnu__::__always_inline__]]
#elif __has_cpp_attribute(msvc::forceinline)
[[msvc::forceinline]]
#endif
#if __has_cpp_attribute(nodiscard)
[[nodiscard]]
#endif
inline constexpr auto transcode_io_decos(T &&t, Deco &&d, Args &&...args)
{
	return ::ufio::operations::decay::transcode_io_decos_decay(
		::ufio::operations::io_stream_transcode_deco_filter_ref(::ufio::freestanding::forward<T>(t)),
		::ufio::freestanding::forward<Deco>(d), ::ufio::freestanding::forward<Args>(args)...);
}

} // namespace operations

} // namespace ufio
