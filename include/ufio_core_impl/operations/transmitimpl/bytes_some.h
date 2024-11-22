#pragma once

namespace ufio
{

namespace details
{

template <typename optstmtype, typename instmtype>
inline constexpr ::ufio::uintfpos_t transmit_bytes_some_main_impl(optstmtype optstm, instmtype instm,
																	 ::ufio::uintfpos_t needtransmit)
{
	/*
	A dummy placeholder implementation
	*/
	constexpr ::std::size_t bfsz{::ufio::details::transmit_buffer_size_cache<1>};
	::ufio::details::local_operator_new_array_ptr<::std::byte> newptr(bfsz);
	::std::byte *buffer_start{newptr.ptr};
	::ufio::uintfpos_t totransmit{needtransmit};
	while (totransmit)
	{
		::std::size_t this_round{bfsz};
		if (totransmit < this_round)
		{
			this_round = static_cast<::std::size_t>(totransmit);
		}
		::std::byte *iter{
			::ufio::operations::decay::read_some_bytes_decay(instm, buffer_start, buffer_start + this_round)};
		if (iter == buffer_start)
		{
			break;
		}
		::ufio::operations::decay::write_all_bytes_decay(optstm, buffer_start, iter);
		totransmit -= static_cast<::std::size_t>(iter - buffer_start);
	}
	return needtransmit - totransmit;
}

} // namespace details

namespace operations
{

namespace decay
{

template <typename optstmtype, typename instmtype>
inline constexpr decltype(auto) transmit_bytes_some_decay(optstmtype optstm, instmtype instm,
														  ::ufio::uintfpos_t totransmit)
{
#if 0
	if constexpr(::ufio::status_output_stream<optstmtype>)
	{
		return status_transmit_bytes_some_define(optstm,instm,totransmit);
	}
	else if constexpr(::ufio::status_input_stream<instmtype>)
	{
		return status_transmit_bytes_some_define(optstm,instm,totransmit);
	}
	else
#endif
	if constexpr (::ufio::operations::decay::defines::has_output_or_io_stream_mutex_ref_define<optstmtype>)
	{
		::ufio::operations::decay::stream_ref_decay_lock_guard lg{
			::ufio::operations::decay::output_stream_mutex_ref_decay(optstm)};
		return ::ufio::operations::decay::transmit_bytes_some_decay(
			::ufio::operations::decay::output_stream_unlocked_ref_decay(optstm), instm, totransmit);
	}
	else if constexpr (::ufio::operations::decay::defines::has_input_or_io_stream_mutex_ref_define<instmtype>)
	{
		::ufio::operations::decay::stream_ref_decay_lock_guard lg{
			::ufio::operations::decay::input_stream_mutex_ref_decay(instm)};
		return ::ufio::operations::decay::transmit_bytes_some_decay(
			optstm, ::ufio::operations::decay::input_stream_unlocked_ref_decay(instm), totransmit);
	}
	else
	{
		return ::ufio::details::transmit_bytes_some_main_impl(optstm, instm, totransmit);
	}
}

} // namespace decay

template <typename optstmtype, typename instmtype>
inline constexpr decltype(auto) transmit_bytes_some(optstmtype &&optstm, instmtype &&instm,
													::ufio::uintfpos_t totransmit)
{
	return ::ufio::operations::decay::transmit_bytes_some_decay(
		::ufio::operations::output_stream_ref(optstm), ::ufio::operations::input_stream_ref(instm), totransmit);
}

} // namespace operations

} // namespace ufio
