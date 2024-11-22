#include <ufio.h>

thread_local ufio::timestamp_scan_state_t<char> state{};

extern "C" int LLVMFuzzerTestOneInput(std::uint8_t const *ptr, std::size_t n) noexcept
{
	ufio::unix_timestamp tsp{};
	auto begin{reinterpret_cast<char const *>(ptr)};
	auto end{begin + n};
	for (;;)
	{
		auto ret{::ufio::details::scn_ctx_define_unix_timestamp_impl<false>(state, begin, end, tsp)};
		if (ret.code != ufio::parse_code::partial)
		{
			break;
		}
	}
	return 0;
}