#pragma once

namespace ufio::operations
{

namespace decay
{

template <typename T>
	requires(::ufio::operations::decay::defines::has_input_or_io_stream_buffer_flush_define<T>)
#if __has_cpp_attribute(__gnu__::__always_inline__)
[[__gnu__::__always_inline__]]
#elif __has_cpp_attribute(msvc::forceinline)
[[msvc::forceinline]]
#endif
inline constexpr void input_stream_buffer_flush_decay(T t)
{
	if constexpr (::ufio::operations::decay::defines::has_input_stream_buffer_flush_define<T>)
	{
		return input_stream_buffer_flush_define(t);
	}
	else
	{
		return io_stream_buffer_flush_define(t);
	}
}

template <typename T>
	requires(::ufio::operations::decay::defines::has_output_or_io_stream_buffer_flush_define<T>)
#if __has_cpp_attribute(__gnu__::__always_inline__)
[[__gnu__::__always_inline__]]
#elif __has_cpp_attribute(msvc::forceinline)
[[msvc::forceinline]]
#endif
inline constexpr void output_stream_buffer_flush_decay(T t)
{
	if constexpr (::ufio::operations::decay::defines::has_output_stream_buffer_flush_define<T>)
	{
		return output_stream_buffer_flush_define(t);
	}
	else
	{
		return io_stream_buffer_flush_define(t);
	}
}

template <typename T>
	requires(::ufio::operations::decay::defines::has_io_stream_buffer_flush_define<T>)
#if __has_cpp_attribute(__gnu__::__always_inline__)
[[__gnu__::__always_inline__]]
#elif __has_cpp_attribute(msvc::forceinline)
[[msvc::forceinline]]
#endif
inline constexpr void io_stream_buffer_flush_decay(T t)
{
	return io_stream_buffer_flush_define(t);
}

template <typename T>
	requires(::ufio::operations::decay::defines::has_input_or_io_stream_seek_bytes_define<T>)
#if __has_cpp_attribute(__gnu__::__always_inline__)
[[__gnu__::__always_inline__]]
#elif __has_cpp_attribute(msvc::forceinline)
[[msvc::forceinline]]
#endif
inline constexpr ::ufio::intfpos_t input_stream_seek_bytes_decay(T t, ::ufio::intfpos_t off,
																	::ufio::seekdir skd)
{
	if constexpr (::ufio::operations::decay::defines::has_input_or_io_stream_seek_bytes_define<T>)
	{
		if constexpr (::ufio::operations::decay::defines::has_ibuffer_basic_operations<T>)
		{
			if (skd == ::ufio::seekdir::cur)
			{
				off = ::ufio::details::adjust_instm_offset(ibuffer_end(t) - ibuffer_curr(t), off);
			}
		}
		if constexpr (::ufio::operations::decay::defines::has_input_or_io_stream_buffer_flush_define<T>)
		{
			::ufio::operations::decay::input_stream_buffer_flush_decay(t);
		}
		if constexpr (::ufio::operations::decay::defines::has_input_stream_seek_bytes_define<T>)
		{
			return input_stream_seek_bytes_define(t, off, skd);
		}
		else
		{
			return io_stream_seek_bytes_define(t, off, skd);
		}
	}
	else if constexpr (::ufio::operations::decay::defines::has_input_or_io_stream_mutex_ref_define<T>)
	{
		::ufio::operations::decay::stream_ref_decay_lock_guard lg{
			::ufio::operations::decay::input_stream_mutex_ref_decay(t)};
		return ::ufio::operations::decay::input_stream_seek_bytes_decay(
			::ufio::operations::decay::input_stream_unlocked_ref_decay(t), off, skd);
	}
}

template <typename T>
#if __has_cpp_attribute(__gnu__::__always_inline__)
[[__gnu__::__always_inline__]]
#elif __has_cpp_attribute(msvc::forceinline)
[[msvc::forceinline]]
#endif
inline constexpr void input_stream_rewind_bytes_decay(T t)
{
	::ufio::operations::decay::input_stream_seek_bytes_decay(t, 0, ::ufio::seekdir::beg);
}

template <typename T>
	requires(::ufio::operations::decay::defines::has_output_or_io_stream_seek_bytes_define<T> ||
			 ::ufio::operations::decay::defines::has_output_or_io_stream_mutex_ref_define<T>)
#if __has_cpp_attribute(__gnu__::__always_inline__)
[[__gnu__::__always_inline__]]
#elif __has_cpp_attribute(msvc::forceinline)
[[msvc::forceinline]]
#endif
inline constexpr ::ufio::intfpos_t output_stream_seek_bytes_decay(T t, ::ufio::intfpos_t off,
																	 ::ufio::seekdir skd)
{
	if constexpr (::ufio::operations::decay::defines::has_output_or_io_stream_seek_bytes_define<T>)
	{
		if constexpr (::ufio::operations::decay::defines::has_output_or_io_stream_buffer_flush_define<T>)
		{
			::ufio::operations::decay::output_stream_buffer_flush_decay(t);
		}
		if constexpr (::ufio::operations::decay::defines::has_output_stream_seek_bytes_define<T>)
		{
			return output_stream_seek_bytes_define(t, off, skd);
		}
		else
		{
			return io_stream_seek_bytes_define(t, off, skd);
		}
	}
	else if constexpr (::ufio::operations::decay::defines::has_output_or_io_stream_mutex_ref_define<T>)
	{
		::ufio::operations::decay::stream_ref_decay_lock_guard lg{
			::ufio::operations::decay::input_stream_mutex_ref_decay(t)};
		return ::ufio::operations::decay::output_stream_seek_bytes_decay(
			::ufio::operations::decay::output_stream_unlocked_ref_decay(t), off, skd);
	}
}

template <typename T>
#if __has_cpp_attribute(__gnu__::__always_inline__)
[[__gnu__::__always_inline__]]
#elif __has_cpp_attribute(msvc::forceinline)
[[msvc::forceinline]]
#endif
inline constexpr void output_stream_rewind_bytes_decay(T t)
{
	::ufio::operations::decay::output_stream_seek_bytes_decay(t, 0, ::ufio::seekdir::beg);
}

template <typename T>
#if 0
requires (::ufio::operations::decay::defines::has_io_stream_mutex_ref_define<T>)
#endif
#if __has_cpp_attribute(__gnu__::__always_inline__)
[[__gnu__::__always_inline__]]
#elif __has_cpp_attribute(msvc::forceinline)
[[msvc::forceinline]]
#endif
inline constexpr ::ufio::intfpos_t io_stream_seek_bytes_decay(T t, ::ufio::intfpos_t off, ::ufio::seekdir skd)
{
	if constexpr (::ufio::operations::decay::defines::has_io_stream_mutex_ref_define<T>)
	{
		::ufio::operations::decay::stream_ref_decay_lock_guard lg{
			::ufio::operations::decay::input_stream_mutex_ref_decay(t)};
		return ::ufio::operations::decay::output_stream_seek_bytes_decay(
			::ufio::operations::decay::output_stream_unlocked_ref_decay(t), off, skd);
	}
	else
	{
		if constexpr (::ufio::operations::decay::defines::has_ibuffer_basic_operations<T>)
		{
			if (skd == ::ufio::seekdir::cur)
			{
				off = ::ufio::details::adjust_instm_offset(ibuffer_end(t) - ibuffer_curr(t), off);
			}
		}
		if constexpr (::ufio::operations::decay::defines::has_io_stream_buffer_flush_define<T>)
		{
			io_stream_buffer_flush_define(t);
		}
		return io_stream_seek_bytes_define(t, off, skd);
	}
}

template <typename T>
#if __has_cpp_attribute(__gnu__::__always_inline__)
[[__gnu__::__always_inline__]]
#elif __has_cpp_attribute(msvc::forceinline)
[[msvc::forceinline]]
#endif
inline constexpr void io_stream_rewind_bytes_decay(T t)
{
	::ufio::operations::decay::io_stream_seek_bytes_decay(t, 0, ::ufio::seekdir::beg);
}

template <typename T>
	requires(::ufio::operations::decay::defines::has_input_or_io_stream_seek_define<T>)
#if __has_cpp_attribute(__gnu__::__always_inline__)
[[__gnu__::__always_inline__]]
#elif __has_cpp_attribute(msvc::forceinline)
[[msvc::forceinline]]
#endif
inline constexpr ::ufio::intfpos_t input_stream_seek_decay(T t, ::ufio::intfpos_t off, ::ufio::seekdir skd)
{
	if constexpr (::ufio::operations::decay::defines::has_input_or_io_stream_seek_define<T>)
	{
		if constexpr (::ufio::operations::decay::defines::has_ibuffer_basic_operations<T>)
		{
			if (skd == ::ufio::seekdir::cur)
			{
				off = ::ufio::details::adjust_instm_offset(ibuffer_end(t) - ibuffer_curr(t), off);
			}
		}
		if constexpr (::ufio::operations::decay::defines::has_input_or_io_stream_buffer_flush_define<T>)
		{
			::ufio::operations::decay::input_stream_buffer_flush_decay(t);
		}
		if constexpr (::ufio::operations::decay::defines::has_input_stream_seek_define<T>)
		{
			return input_stream_seek_define(t, off, skd);
		}
		else
		{
			return io_stream_seek_define(t, off, skd);
		}
	}
	else if constexpr (::ufio::operations::decay::defines::has_input_or_io_stream_mutex_ref_define<T>)
	{
		::ufio::operations::decay::stream_ref_decay_lock_guard lg{
			::ufio::operations::decay::input_stream_mutex_ref_decay(t)};
		return ::ufio::operations::decay::input_stream_seek_decay(
			::ufio::operations::decay::input_stream_unlocked_ref_decay(t), off, skd);
	}
}

template <typename T>
#if __has_cpp_attribute(__gnu__::__always_inline__)
[[__gnu__::__always_inline__]]
#elif __has_cpp_attribute(msvc::forceinline)
[[msvc::forceinline]]
#endif
inline constexpr void input_stream_rewind_decay(T t)
{
	::ufio::operations::decay::input_stream_seek_decay(t, 0, ::ufio::seekdir::beg);
}

template <typename T>
	requires(::ufio::operations::decay::defines::has_output_or_io_stream_seek_define<T> ||
			 ::ufio::operations::decay::defines::has_output_or_io_stream_mutex_ref_define<T>)
#if __has_cpp_attribute(__gnu__::__always_inline__)
[[__gnu__::__always_inline__]]
#elif __has_cpp_attribute(msvc::forceinline)
[[msvc::forceinline]]
#endif
inline constexpr ::ufio::intfpos_t output_stream_seek_decay(T t, ::ufio::intfpos_t off, ::ufio::seekdir skd)
{
	if constexpr (::ufio::operations::decay::defines::has_output_or_io_stream_seek_define<T>)
	{
		if constexpr (::ufio::operations::decay::defines::has_output_or_io_stream_buffer_flush_define<T>)
		{
			::ufio::operations::decay::output_stream_buffer_flush_decay(t);
		}
		if constexpr (::ufio::operations::decay::defines::has_output_stream_seek_define<T>)
		{
			return output_stream_seek_define(t, off, skd);
		}
		else
		{
			return io_stream_seek_define(t, off, skd);
		}
	}
	else if constexpr (::ufio::operations::decay::defines::has_output_or_io_stream_mutex_ref_define<T>)
	{
		::ufio::operations::decay::stream_ref_decay_lock_guard lg{
			::ufio::operations::decay::input_stream_mutex_ref_decay(t)};
		return ::ufio::operations::decay::output_stream_seek_decay(
			::ufio::operations::decay::output_stream_unlocked_ref_decay(t), off, skd);
	}
}

template <typename T>
#if __has_cpp_attribute(__gnu__::__always_inline__)
[[__gnu__::__always_inline__]]
#elif __has_cpp_attribute(msvc::forceinline)
[[msvc::forceinline]]
#endif
inline constexpr void output_stream_rewind_decay(T t)
{
	::ufio::operations::decay::output_stream_seek_decay(t, 0, ::ufio::seekdir::beg);
}

template <typename T>
	requires(::ufio::operations::decay::defines::has_io_stream_mutex_ref_define<T> ||
			 ::ufio::operations::decay::defines::has_io_stream_seek_define<T>)
#if __has_cpp_attribute(__gnu__::__always_inline__)
[[__gnu__::__always_inline__]]
#elif __has_cpp_attribute(msvc::forceinline)
[[msvc::forceinline]]
#endif
inline constexpr ::ufio::intfpos_t io_stream_seek_decay(T t, ::ufio::intfpos_t off, ::ufio::seekdir skd)
{
	if constexpr (::ufio::operations::decay::defines::has_io_stream_mutex_ref_define<T>)
	{
		::ufio::operations::decay::stream_ref_decay_lock_guard lg{
			::ufio::operations::decay::input_stream_mutex_ref_decay(t)};
		return ::ufio::operations::decay::output_stream_seek_decay(
			::ufio::operations::decay::output_stream_unlocked_ref_decay(t), off, skd);
	}
	else
	{
		if constexpr (::ufio::operations::decay::defines::has_ibuffer_basic_operations<T>)
		{
			if (skd == ::ufio::seekdir::cur)
			{
				off = ::ufio::details::adjust_instm_offset(ibuffer_end(t) - ibuffer_curr(t), off);
			}
		}
		if constexpr (::ufio::operations::decay::defines::has_io_stream_buffer_flush_define<T>)
		{
			io_stream_buffer_flush_define(t);
		}
		return io_stream_seek_define(t, off, skd);
	}
}

template <typename T>
#if __has_cpp_attribute(__gnu__::__always_inline__)
[[__gnu__::__always_inline__]]
#elif __has_cpp_attribute(msvc::forceinline)
[[msvc::forceinline]]
#endif
inline constexpr void io_stream_rewind_decay(T t)
{
	::ufio::operations::decay::io_stream_seek_decay(t, 0, ::ufio::seekdir::beg);
}

} // namespace decay

template <typename T>
#if __has_cpp_attribute(__gnu__::__always_inline__)
[[__gnu__::__always_inline__]]
#elif __has_cpp_attribute(msvc::forceinline)
[[msvc::forceinline]]
#endif
inline constexpr ::ufio::intfpos_t input_stream_seek_bytes(T &&t, ::ufio::intfpos_t off, ::ufio::seekdir skd)
{
	return ::ufio::operations::decay::input_stream_seek_bytes_decay(::ufio::operations::input_stream_ref(t), off,
																	   skd);
}

template <typename T>
#if __has_cpp_attribute(__gnu__::__always_inline__)
[[__gnu__::__always_inline__]]
#elif __has_cpp_attribute(msvc::forceinline)
[[msvc::forceinline]]
#endif
inline constexpr ::ufio::intfpos_t output_stream_seek_bytes(T &&t, ::ufio::intfpos_t off, ::ufio::seekdir skd)
{
	return ::ufio::operations::decay::output_stream_seek_bytes_decay(::ufio::operations::output_stream_ref(t),
																		off, skd);
}

template <typename T>
#if __has_cpp_attribute(__gnu__::__always_inline__)
[[__gnu__::__always_inline__]]
#elif __has_cpp_attribute(msvc::forceinline)
[[msvc::forceinline]]
#endif
inline constexpr ::ufio::intfpos_t io_stream_seek_bytes(T &&t, ::ufio::intfpos_t off, ::ufio::seekdir skd)
{
	return ::ufio::operations::decay::io_stream_seek_bytes_decay(::ufio::operations::io_stream_ref(t), off, skd);
}

template <typename T>
#if __has_cpp_attribute(__gnu__::__always_inline__)
[[__gnu__::__always_inline__]]
#elif __has_cpp_attribute(msvc::forceinline)
[[msvc::forceinline]]
#endif
inline constexpr ::ufio::intfpos_t input_stream_seek(T &&t, ::ufio::intfpos_t off, ::ufio::seekdir skd)
{
	return ::ufio::operations::decay::input_stream_seek_decay(::ufio::operations::input_stream_ref(t), off, skd);
}

template <typename T>
#if __has_cpp_attribute(__gnu__::__always_inline__)
[[__gnu__::__always_inline__]]
#elif __has_cpp_attribute(msvc::forceinline)
[[msvc::forceinline]]
#endif
inline constexpr ::ufio::intfpos_t output_stream_seek(T &&t, ::ufio::intfpos_t off, ::ufio::seekdir skd)
{
	return ::ufio::operations::decay::output_stream_seek_decay(::ufio::operations::output_stream_ref(t), off,
																  skd);
}

template <typename T>
#if __has_cpp_attribute(__gnu__::__always_inline__)
[[__gnu__::__always_inline__]]
#elif __has_cpp_attribute(msvc::forceinline)
[[msvc::forceinline]]
#endif
inline constexpr ::ufio::intfpos_t io_stream_seek(T &&t, ::ufio::intfpos_t off, ::ufio::seekdir skd)
{
	return ::ufio::operations::decay::io_stream_seek_decay(::ufio::operations::io_stream_ref(t), off, skd);
}

template <typename T>
#if __has_cpp_attribute(__gnu__::__always_inline__)
[[__gnu__::__always_inline__]]
#elif __has_cpp_attribute(msvc::forceinline)
[[msvc::forceinline]]
#endif
inline constexpr void input_stream_rewind_bytes(T &&t)
{
	::ufio::operations::decay::input_stream_rewind_bytes_decay(::ufio::operations::input_stream_ref(t));
}

template <typename T>
#if __has_cpp_attribute(__gnu__::__always_inline__)
[[__gnu__::__always_inline__]]
#elif __has_cpp_attribute(msvc::forceinline)
[[msvc::forceinline]]
#endif
inline constexpr void output_stream_rewind_bytes(T &&t)
{
	::ufio::operations::decay::output_stream_rewind_bytes_decay(::ufio::operations::output_stream_ref(t));
}

template <typename T>
#if __has_cpp_attribute(__gnu__::__always_inline__)
[[__gnu__::__always_inline__]]
#elif __has_cpp_attribute(msvc::forceinline)
[[msvc::forceinline]]
#endif
inline constexpr void io_stream_rewind_bytes(T &&t)
{
	::ufio::operations::decay::io_stream_rewind_bytes_decay(::ufio::operations::io_stream_ref(t));
}

template <typename T>
#if __has_cpp_attribute(__gnu__::__always_inline__)
[[__gnu__::__always_inline__]]
#elif __has_cpp_attribute(msvc::forceinline)
[[msvc::forceinline]]
#endif
inline constexpr void input_stream_rewind(T &&t)
{
	::ufio::operations::decay::input_stream_rewind_decay(::ufio::operations::input_stream_ref(t));
}

template <typename T>
#if __has_cpp_attribute(__gnu__::__always_inline__)
[[__gnu__::__always_inline__]]
#elif __has_cpp_attribute(msvc::forceinline)
[[msvc::forceinline]]
#endif
inline constexpr void output_stream_rewind(T &&t)
{
	::ufio::operations::decay::output_stream_rewind_decay(::ufio::operations::output_stream_ref(t));
}

template <typename T>
#if __has_cpp_attribute(__gnu__::__always_inline__)
[[__gnu__::__always_inline__]]
#elif __has_cpp_attribute(msvc::forceinline)
[[msvc::forceinline]]
#endif
inline constexpr void io_stream_rewind(T &&t)
{
	::ufio::operations::decay::io_stream_rewind_decay(::ufio::operations::io_stream_ref(t));
}

template <typename T>
#if __has_cpp_attribute(__gnu__::__always_inline__)
[[__gnu__::__always_inline__]]
#elif __has_cpp_attribute(msvc::forceinline)
[[msvc::forceinline]]
#endif
inline constexpr void input_stream_buffer_flush(T &&t)
{
	::ufio::operations::decay::input_stream_buffer_flush_decay(::ufio::operations::input_stream_ref(t));
}

template <typename T>
#if __has_cpp_attribute(__gnu__::__always_inline__)
[[__gnu__::__always_inline__]]
#elif __has_cpp_attribute(msvc::forceinline)
[[msvc::forceinline]]
#endif
inline constexpr void output_stream_buffer_flush(T &&t)
{
	::ufio::operations::decay::output_stream_buffer_flush_decay(::ufio::operations::output_stream_ref(t));
}

template <typename T>
#if __has_cpp_attribute(__gnu__::__always_inline__)
[[__gnu__::__always_inline__]]
#elif __has_cpp_attribute(msvc::forceinline)
[[msvc::forceinline]]
#endif
inline constexpr void io_stream_buffer_flush(T &&t)
{
	::ufio::operations::decay::io_stream_buffer_flush_decay(::ufio::operations::io_stream_ref(t));
}

} // namespace ufio::operations
