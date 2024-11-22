#pragma once

namespace ufio
{

#ifdef BOOST_GRAPH_DETAIL_EDGE_HPP

template <::std::integral char_type, ::ufio::buffer_output_stream bos, typename directed, typename vertex>
inline constexpr void print_define(io_reserve_type_t<char_type, ::boost::detail::edge_desc_impl<directed, vertex>>,
								   bos b, ::boost::detail::edge_desc_impl<directed, vertex> const &e)
{
	print_freestanding(b, ufio::mnp::chvw(char_literal_v<u8'(', char_type>), e.m_source,
					   ufio::mnp::chvw(char_literal_v<u8',', char_type>), e.m_target,
					   ufio::mnp::chvw(char_literal_v<u8')', char_type>));
}

#endif
} // namespace ufio
