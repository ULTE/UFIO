﻿#pragma once

namespace ufio
{

struct allocation_mmap_options
{
	bool write_back{};
	explicit constexpr allocation_mmap_options() noexcept = default;
	constexpr allocation_mmap_options(::ufio::mmap_prot, ::ufio::mmap_flags flagsv) noexcept
	{
		int exclusiveflags{static_cast<int>(flagsv & ::ufio::mmap_flags::map_type)};
		if (exclusiveflags == 3)
		{
			exclusiveflags = 1;
		}
		if (exclusiveflags == 1)
		{
			this->write_back = true;
		}
	}
};

} // namespace ufio
