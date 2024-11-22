#pragma once

namespace ufio
{

struct nt_mmap_options
{
	void *objAttr{};
	::std::uint_least32_t dwDesiredAccess{};
	::std::uint_least32_t flProtect{};
	::std::uint_least32_t attributes{};
	::std::uint_least32_t viewShare{};

	explicit constexpr nt_mmap_options() noexcept = default;
	constexpr nt_mmap_options(::ufio::mmap_prot protv, ::ufio::mmap_flags flagsv) noexcept
	{
		::std::uint_least32_t flprotecttemp{};
		::std::uint_least32_t dwDesiredAccesstemp{0x000F0000 | 0x0001 | 0x0004};

		int exclusiveflags{static_cast<int>(flagsv & ::ufio::mmap_flags::map_type)};
		if (exclusiveflags == 3)
		{
			exclusiveflags = 1;
		}

		if ((protv & ::ufio::mmap_prot::prot_exec) == ::ufio::mmap_prot::prot_exec)
		{
			if ((protv & ::ufio::mmap_prot::prot_read) == ::ufio::mmap_prot::prot_read)
			{
				if ((protv & ::ufio::mmap_prot::prot_write) == ::ufio::mmap_prot::prot_write)
				{
					flprotecttemp |= 0x40 /*PAGE_EXECUTE_READWRITE*/;
					dwDesiredAccesstemp |= (0x0002 | 0x0008);
				}
				else
				{
					flprotecttemp |= 0x20 /*PAGE_EXECUTE_READ*/;
					dwDesiredAccesstemp |= 0x0008;
				}
			}
			else if ((protv & ::ufio::mmap_prot::prot_write) == ::ufio::mmap_prot::prot_write)
			{
				if (exclusiveflags == 2)
				{
					flprotecttemp |= 0x80 /*PAGE_EXECUTE_WRITECOPY*/;
#if !defined(_WIN32_WINNT) || _WIN32_WINNT >= 0x0600 /* NtCurrentPeb()->OSMajorVersion >= 6 */
					dwDesiredAccesstemp |= (0x0002 | 0x0008);
#endif
				}
				else
				{
					flprotecttemp |= 0x40 /*PAGE_EXECUTE_READWRITE*/;
					dwDesiredAccesstemp |= (0x0002 | 0x0008);
				}
			}
		}
		else
		{
			if ((protv & ::ufio::mmap_prot::prot_read) == ::ufio::mmap_prot::prot_read)
			{
				if ((protv & ::ufio::mmap_prot::prot_write) == ::ufio::mmap_prot::prot_write)
				{
					flprotecttemp |= 0x4 /*PAGE_READWRITE*/;
					dwDesiredAccesstemp |= 0x0002;
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
					dwDesiredAccesstemp |= 0x0002;
				}
			}
		}

		if ((flagsv & ::ufio::mmap_flags::map_hugetlb) == ::ufio::mmap_flags::map_hugetlb)
		{
			flprotecttemp |= 0x80000000;
		}

		this->dwDesiredAccess = dwDesiredAccesstemp;
		this->flProtect = flprotecttemp;
		this->attributes = 0x08000000;
		this->viewShare = 0x01;
	}
};

} // namespace ufio
