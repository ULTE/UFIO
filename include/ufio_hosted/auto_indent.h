#pragma once

namespace ufio
{

template <::std::ranges::contiguous_range rg,
		  typename containe = ::ufio::containers::vector<::std::size_t, ::ufio::native_thread_local_allocator>>
	requires ::std::integral<::std::ranges::range_value_t<rg>>
inline constexpr auto auto_indent(rg &&r)
{
	if constexpr (::std::is_array_v<::std::remove_cvref_t<rg>>)
	{
		return ::ufio::details::calculate_auto_width_result<containe>(
			::std::ranges::data(r), ::std::ranges::data(r) + (::std::ranges::size(r) - 1));
	}
	else
	{
		return ::ufio::details::calculate_auto_width_result<containe>(
			::std::ranges::data(r), ::std::ranges::data(r) + ::std::ranges::size(r));
	}
}

} // namespace ufio
