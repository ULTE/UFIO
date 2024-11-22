#pragma once

namespace ufio
{

class iocp_overlapped_base : public ufio::win32::overlapped
{
public:
	constexpr iocp_overlapped_base()
		: ufio::win32::overlapped{}
	{}
#if __cpp_constexpr >= 201907L
	constexpr
#endif
		virtual void
		invoke(::std::size_t) noexcept = 0;
#if __cpp_constexpr >= 201907L
	constexpr
#endif
		virtual ~iocp_overlapped_base() = default;
};

} // namespace ufio
