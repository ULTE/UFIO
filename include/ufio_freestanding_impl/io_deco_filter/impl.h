#pragma once

#include "destroy.h"
#include "io_deco_filter.h"
#include "io_deco_filter_ref.h"
#include "read.h"
#include "write.h"

namespace ufio
{

template <typename handletype, typename decorators, typename allocator_type = ::ufio::native_global_allocator>
using basic_io_deco_filt = basic_io_deco_filter<
	handletype,
	basic_io_buffer_traits<::ufio::buffer_mode::in | ::ufio::buffer_mode::out, allocator_type,
						   typename decltype(::ufio::operations::input_stream_ref(
							   *static_cast<handletype *>(nullptr)))::input_char_type,
						   typename decltype(::ufio::operations::output_stream_ref(
							   *static_cast<handletype *>(nullptr)))::output_char_type>,
	decorators>;

}
