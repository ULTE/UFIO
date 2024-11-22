#include <ufio_dsal/array.h>
#include <ufio_dsal/index_span.h>
#include <ufio.h>

int main()
{
	::ufio::array<::std::size_t, 40> arr{4, 6, 7};
	::ufio::index_span<::std::size_t, 5> sp(arr);
	for (auto const &e : sp)
	{
		::ufio::io::println(e);
	}
}