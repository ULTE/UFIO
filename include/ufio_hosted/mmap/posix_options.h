#pragma once

namespace ufio
{

struct posix_mmap_options
{
	void *addr{};
	int prot{};
	int flags{};
	explicit constexpr posix_mmap_options() noexcept = default;
	constexpr posix_mmap_options(int protv, int flagsv) noexcept
		: prot(protv), flags(flagsv)
	{}
#ifdef __linux__
	constexpr posix_mmap_options(::ufio::mmap_prot protv, ::ufio::mmap_flags flagsv) noexcept
		: prot(static_cast<int>(protv)), flags(static_cast<int>(flagsv))
	{
#ifdef MAP_UNINITIALIZED
		if constexpr (MAP_UNINITIALIZED == 0)
		{
			if ((flagsv & ::ufio::mmap_flags::map_uninitialized) == ::ufio::mmap_flags::map_uninitialized)
			{
				flags -= 0x4000000;
			}
		}
#endif
	}
#else
	constexpr posix_mmap_options(::ufio::mmap_prot protv, ::ufio::mmap_flags flagsv) noexcept
	{
		int prottemp{};
#ifdef PROT_READ
		if ((protv & ::ufio::mmap_prot::prot_read) == ::ufio::mmap_prot::prot_read)
		{
			prottemp |= PROT_READ;
		}
#endif
#ifdef PROT_WRITE
		if ((protv & ::ufio::mmap_prot::prot_write) == ::ufio::mmap_prot::prot_write)
		{
			prottemp |= PROT_WRITE;
		}
#endif
#ifdef PROT_EXEC
		if ((protv & ::ufio::mmap_prot::prot_exec) == ::ufio::mmap_prot::prot_exec)
		{
			prottemp |= PROT_EXEC;
		}
#endif
#ifdef PROT_MTE
		if ((protv & ::ufio::mmap_prot::prot_mte) == ::ufio::mmap_prot::prot_mte)
		{
			prottemp |= PROT_MTE;
		}
#endif
#ifdef PROT_SEM
		if ((protv & ::ufio::mmap_prot::prot_sem) == ::ufio::mmap_prot::prot_sem)
		{
			prottemp |= PROT_SEM;
		}
#endif
#ifdef PROT_GROWSDOWN
		if ((protv & ::ufio::mmap_prot::prot_growsdown) == ::ufio::mmap_prot::prot_growsdown)
		{
			prottemp |= PROT_GROWSDOWN;
		}
#endif

		int flagstemp{};

#ifdef MAP_FIXED
		if ((flagsv & ::ufio::mmap_flags::map_fixed) == ::ufio::mmap_flags::map_fixed)
		{
			flagstemp |= MAP_FIXED;
		}
#endif
#if defined(MAP_ANONYMOUS) || defined(MAP_ANON)
		if ((flagsv & ::ufio::mmap_flags::map_anonymous) == ::ufio::mmap_flags::map_anonymous)
		{
#ifdef MAP_ANONYMOUS
			flagstemp |= MAP_ANONYMOUS;
#else
			flagstemp |= MAP_ANON;
#endif
		}
#endif
#ifdef MAP_32BIT
		if ((flagsv & ::ufio::mmap_flags::map_32bit) == ::ufio::mmap_flags::map_32bit)
		{
			flagstemp |= MAP_32BIT;
		}
#endif
#ifdef MAP_ABOVE4G
		if ((flagsv & ::ufio::mmap_flags::map_above4g) == ::ufio::mmap_flags::map_above4g)
		{
			flagstemp |= MAP_ABOVE4G;
		}
#endif

#ifdef MAP_HASSEMAPHORE
		if ((flagsv & ::ufio::mmap_flags::map_hassemaphore) == ::ufio::mmap_flags::map_hassemaphore)
		{
			flagstemp |= MAP_HASSEMAPHORE;
		}
#endif

#ifdef MAP_INHERIT
		if ((flagsv & ::ufio::mmap_flags::map_inherit) == ::ufio::mmap_flags::map_inherit)
		{
			flagstemp |= MAP_INHERIT;
		}
#endif

#ifdef MAP_UNALIGNED
		if ((flagsv & ::ufio::mmap_flags::map_unaligned) == ::ufio::mmap_flags::map_unaligned)
		{
			flagstemp |= MAP_UNALIGNED;
		}
#endif

#ifdef MAP_GROWSDOWN
		if ((flagsv & ::ufio::mmap_flags::map_growsdown) == ::ufio::mmap_flags::map_growsdown)
		{
			flagstemp |= MAP_GROWSDOWN;
		}
#endif

#ifdef MAP_DENYWRITE
		if ((flagsv & ::ufio::mmap_flags::map_denywrite) == ::ufio::mmap_flags::map_denywrite)
		{
			flagstemp |= MAP_DENYWRITE;
		}
#endif

#ifdef MAP_EXECUTABLE
		if ((flagsv & ::ufio::mmap_flags::map_executable) == ::ufio::mmap_flags::map_executable)
		{
			flagstemp |= MAP_EXECUTABLE;
		}
#endif

#ifdef MAP_LOCKED
		if ((flagsv & ::ufio::mmap_flags::map_locked) == ::ufio::mmap_flags::map_locked)
		{
			flagstemp |= MAP_LOCKED;
		}
#endif

#ifdef MAP_NORESERVE
		if ((flagsv & ::ufio::mmap_flags::map_noreserve) == ::ufio::mmap_flags::map_noreserve)
		{
			flagstemp |= MAP_NORESERVE;
		}
#endif

#ifdef MAP_POPULATE
		if ((flagsv & ::ufio::mmap_flags::map_populate) == ::ufio::mmap_flags::map_populate)
		{
			flagstemp |= MAP_POPULATE;
		}
#endif

#ifdef MAP_NONBLOCK
		if ((flagsv & ::ufio::mmap_flags::map_nonblock) == ::ufio::mmap_flags::map_nonblock)
		{
			flagstemp |= MAP_NONBLOCK;
		}
#endif

#ifdef MAP_STACK
		if ((flagsv & ::ufio::mmap_flags::map_stack) == ::ufio::mmap_flags::map_stack)
		{
			flagstemp |= MAP_STACK;
		}
#endif

#ifdef MAP_HUGETLB
		if ((flagsv & ::ufio::mmap_flags::map_hugetlb) == ::ufio::mmap_flags::map_hugetlb)
		{
			flagstemp |= MAP_HUGETLB;
		}
#endif

#ifdef MAP_FIXED_NOREPLACE
		if ((flagsv & ::ufio::mmap_flags::map_fixed_noreplace) == ::ufio::mmap_flags::map_fixed_noreplace)
		{
			flagstemp |= MAP_FIXED_NOREPLACE;
		}
#endif

#ifdef MAP_HUGE_2MB
		if ((flagsv & ::ufio::mmap_flags::map_huge_2mb) == ::ufio::mmap_flags::map_huge_2mb)
		{
			flagstemp |= MAP_HUGE_2MB;
		}
#endif

#ifdef MAP_HUGE_1GB
		if ((flagsv & ::ufio::mmap_flags::map_huge_1gb) == ::ufio::mmap_flags::map_huge_1gb)
		{
			flagstemp |= MAP_HUGE_1GB;
		}
#endif
		auto exclusiveflags{static_cast<int>(flagsv & ::ufio::mmap_flags::map_type)};
		switch (exclusiveflags)
		{
#ifdef MAP_SHARED_VALIDATE
		case 3:
			flagstemp |= MAP_SHARED_VALIDATE;
			break;
#endif
		case 2:
			flagstemp |= MAP_PRIVATE;
			break;
		case 1:
			flagstemp |= MAP_SHARED;
			break;
		}
		this->prot = prottemp;
		this->flags = flagstemp;
	}
#endif
};

} // namespace ufio
