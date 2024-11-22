#pragma once

namespace ufio
{

struct single_thread_noop_mutex
{
	constexpr void lock() noexcept
	{}
	constexpr void unlock() noexcept
	{}
	constexpr void try_lock() noexcept
	{}
};

} // namespace ufio