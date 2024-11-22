#pragma once

namespace ufio
{

namespace operations::decay::defines
{

template <typename T>
concept has_input_stream_buffer_flush_define = requires(T t) { input_stream_buffer_flush_define(t); };

template <typename T>
concept has_output_stream_buffer_flush_define = requires(T t) { output_stream_buffer_flush_define(t); };

template <typename T>
concept has_io_stream_buffer_flush_define = requires(T t) { io_stream_buffer_flush_define(t); };

template <typename T>
concept has_input_or_io_stream_buffer_flush_define =
	::ufio::operations::decay::defines::has_io_stream_buffer_flush_define<T> ||
	::ufio::operations::decay::defines::has_input_stream_buffer_flush_define<T>;

template <typename T>
concept has_output_or_io_stream_buffer_flush_define =
	::ufio::operations::decay::defines::has_io_stream_buffer_flush_define<T> ||
	::ufio::operations::decay::defines::has_output_stream_buffer_flush_define<T>;

template <typename T>
concept has_input_stream_seek_define = requires(T instm, ::ufio::intfpos_t pos, ::ufio::seekdir sdir) {
	{ input_stream_seek_define(instm, pos, sdir) } -> ::std::same_as<::ufio::intfpos_t>;
};

template <typename T>
concept has_input_stream_seek_bytes_define = requires(T instm, ::ufio::intfpos_t pos, ::ufio::seekdir sdir) {
	{ input_stream_seek_bytes_define(instm, pos, sdir) } -> ::std::same_as<::ufio::intfpos_t>;
};

template <typename T>
concept has_output_stream_seek_define = requires(T instm, ::ufio::intfpos_t pos, ::ufio::seekdir sdir) {
	{ output_stream_seek_define(instm, pos, sdir) } -> ::std::same_as<::ufio::intfpos_t>;
};

template <typename T>
concept has_output_stream_seek_bytes_define = requires(T instm, ::ufio::intfpos_t pos, ::ufio::seekdir sdir) {
	{ output_stream_seek_bytes_define(instm, pos, sdir) } -> ::std::same_as<::ufio::intfpos_t>;
};

template <typename T>
concept has_io_stream_seek_define = requires(T instm, ::ufio::intfpos_t pos, ::ufio::seekdir sdir) {
	{ io_stream_seek_define(instm, pos, sdir) } -> ::std::same_as<::ufio::intfpos_t>;
};

template <typename T>
concept has_io_stream_seek_bytes_define = requires(T instm, ::ufio::intfpos_t pos, ::ufio::seekdir sdir) {
	{ io_stream_seek_bytes_define(instm, pos, sdir) } -> ::std::same_as<::ufio::intfpos_t>;
};

template <typename T>
concept has_input_or_io_stream_seek_define = ::ufio::operations::decay::defines::has_io_stream_seek_define<T> ||
											 ::ufio::operations::decay::defines::has_input_stream_seek_define<T>;

template <typename T>
concept has_output_or_io_stream_seek_define = ::ufio::operations::decay::defines::has_io_stream_seek_define<T> ||
											  ::ufio::operations::decay::defines::has_output_stream_seek_define<T>;

template <typename T>
concept has_input_or_io_stream_seek_bytes_define =
	::ufio::operations::decay::defines::has_io_stream_seek_bytes_define<T> ||
	::ufio::operations::decay::defines::has_input_stream_seek_bytes_define<T>;

template <typename T>
concept has_output_or_io_stream_seek_bytes_define =
	::ufio::operations::decay::defines::has_io_stream_seek_bytes_define<T> ||
	::ufio::operations::decay::defines::has_output_stream_seek_bytes_define<T>;

} // namespace operations::decay::defines

} // namespace ufio
