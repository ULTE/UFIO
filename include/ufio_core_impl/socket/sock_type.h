#pragma once

namespace ufio
{

enum class sock_type : char8_t
{
	stream,
	dgram,
	seqpacket,
	raw,
	rdm,
	packet
};

} // namespace ufio
