#pragma once
namespace ufio
{

namespace operations::defines
{
template <typename handletype>
concept available_add_ibuf = requires {
	typename decltype(::ufio::operations::input_stream_ref(*static_cast<handletype *>(nullptr)))::input_char_type;
};

template <typename handletype>
concept available_add_obuf = requires {
	typename decltype(::ufio::operations::output_stream_ref(*static_cast<handletype *>(nullptr)))::output_char_type;
};

template <typename handletype>
concept available_add_iobuf = available_add_ibuf<handletype> || available_add_obuf<handletype>;

} // namespace operations::defines
} // namespace ufio
