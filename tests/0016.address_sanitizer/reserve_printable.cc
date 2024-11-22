#include <ufio.h>

struct foo
{
};

inline constexpr std::size_t print_reserve_size(::ufio::io_reserve_type_t<char, foo>) noexcept
{
	return 5;
}

inline constexpr char *print_reserve_define(::ufio::io_reserve_type_t<char, foo>, char *out, foo f)
{
	out[7] = 2;
	return out + 5;
}

static_assert(ufio::reserve_printable<char, foo>);

using namespace ufio::io;

int main()
{
	foo f;
	println("Hellowefqewjopfewjf");
	print(f);
}

/*
-fsanitize=address -DUFIO_SANITIZE_IO_BUFFER should detect bug here
*/