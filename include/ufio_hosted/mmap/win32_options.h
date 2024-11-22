#pragma once

namespace ufio
{

struct win32_mmap_options
{
	::std::uint_least32_t flProtect{};
	::std::uint_least32_t dwDesiredAccess{};
	void *lpFileMappingAttributes{};
	void *lpName{};

	explicit constexpr win32_mmap_options() noexcept = default;
	constexpr win32_mmap_options(::ufio::mmap_prot protv, ::ufio::mmap_flags flagsv) noexcept
	{
		::std::uint_least32_t flprotecttemp{};
		::std::uint_least32_t dwDesiredAccesstemp{};

		int exclusiveflags{static_cast<int>(flagsv & ::ufio::mmap_flags::map_type)};
		if (exclusiveflags == 3)
		{
			exclusiveflags = 1;
		}

		if (exclusiveflags == 2)
		{
			dwDesiredAccesstemp |= 0x00000001 /*FILE_MAP_COPY*/;
		}

		if ((protv & ::ufio::mmap_prot::prot_exec) == ::ufio::mmap_prot::prot_exec)
		{
			if ((protv & ::ufio::mmap_prot::prot_read) == ::ufio::mmap_prot::prot_read)
			{
				if ((protv & ::ufio::mmap_prot::prot_write) == ::ufio::mmap_prot::prot_write)
				{
					flprotecttemp |= 0x40 /*PAGE_EXECUTE_READWRITE*/;
				}
				else
				{
					flprotecttemp |= 0x20 /*PAGE_EXECUTE_READ*/;
				}
			}
			else if ((protv & ::ufio::mmap_prot::prot_write) == ::ufio::mmap_prot::prot_write)
			{
				if (exclusiveflags == 2)
				{
					flprotecttemp |= 0x80 /*PAGE_EXECUTE_WRITECOPY*/;
				}
				else
				{
					flprotecttemp |= 0x40 /*PAGE_EXECUTE_READWRITE*/;
				}
			}
			dwDesiredAccesstemp |= 0x00000020 /*FILE_MAP_EXECUTE*/;
		}
		else
		{
			if ((protv & ::ufio::mmap_prot::prot_read) == ::ufio::mmap_prot::prot_read)
			{
				if ((protv & ::ufio::mmap_prot::prot_write) == ::ufio::mmap_prot::prot_write)
				{
					flprotecttemp |= 0x4 /*PAGE_READWRITE*/;
				}
				else
				{
					flprotecttemp |= 0x2 /*PAGE_READONLY*/;
				}
			}
			else if ((protv & ::ufio::mmap_prot::prot_write) == ::ufio::mmap_prot::prot_write)
			{
				if (exclusiveflags == 2)
				{
					flprotecttemp |= 0x8 /*PAGE_WRITECOPY*/;
				}
				else
				{
					flprotecttemp |= 0x4 /*PAGE_READWRITE*/;
				}
			}
		}

		if ((protv & ::ufio::mmap_prot::prot_read) == ::ufio::mmap_prot::prot_read &&
			(protv & ::ufio::mmap_prot::prot_write) == ::ufio::mmap_prot::prot_write)
		{
			dwDesiredAccesstemp |= 0x00000004 /*FILE_MAP_ALL_ACCESS*/;
		}
		else
		{
			if ((protv & ::ufio::mmap_prot::prot_write) == ::ufio::mmap_prot::prot_write)
			{
				dwDesiredAccesstemp |= 0x00000002 /*FILE_MAP_WRITE*/;
			}
			if ((protv & ::ufio::mmap_prot::prot_read) == ::ufio::mmap_prot::prot_read)
			{
				dwDesiredAccesstemp |= 0x00000004 /*FILE_MAP_READ*/;
			}
		}
		if ((flagsv & ::ufio::mmap_flags::map_hugetlb) == ::ufio::mmap_flags::map_hugetlb)
		{
			flprotecttemp |= 0x80000000;
			dwDesiredAccesstemp |= 0x20000000;
		}
		this->flProtect = flprotecttemp;
		this->dwDesiredAccess = dwDesiredAccesstemp;
	}
};

} // namespace ufio
