#pragma once

#include "mode.h"
#include "io_buffer.h"
#include "io_buffer_ref.h"
#include "output.h"
#include "input.h"
#include "destroy.h"

namespace ufio
{

template <typename handletype, typename allocator_type = ::ufio::native_global_allocator>
using basic_ibuf =
	basic_io_buffer<handletype, basic_io_buffer_traits<::ufio::buffer_mode::in, allocator_type,
													   typename decltype(::ufio::operations::input_stream_ref(
														   *static_cast<handletype *>(nullptr)))::input_char_type,
													   void>>;

template <typename handletype, typename allocator_type = ::ufio::native_global_allocator>
using basic_obuf =
	basic_io_buffer<handletype, basic_io_buffer_traits<::ufio::buffer_mode::out, allocator_type, void,
													   typename decltype(::ufio::operations::output_stream_ref(
														   *static_cast<handletype *>(nullptr)))::output_char_type>>;

template <typename handletype, typename allocator_type = ::ufio::native_global_allocator>
using basic_iobuf =
	basic_io_buffer<handletype, basic_io_buffer_traits<::ufio::buffer_mode::in | ::ufio::buffer_mode::out |
														   ::ufio::buffer_mode::tie,
													   allocator_type,
													   typename decltype(::ufio::operations::input_stream_ref(
														   *static_cast<handletype *>(nullptr)))::input_char_type,
													   typename decltype(::ufio::operations::output_stream_ref(
														   *static_cast<handletype *>(nullptr)))::output_char_type>>;

} // namespace ufio

#include "io_buffer_transcode_ref.h"