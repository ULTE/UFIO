#include <ufio.h>
#include <ufio_device.h>
#include <ufio_dsal/array.h>
#include <ufio_dsal/string.h>
#include <ufio_dsal/string_view.h>
#include <ufio_dsal/span.h>

int main()
{
	::ufio::ibuf_file nf(u8"wsme.txt");
	::ufio::array<char, 10> buffer;
	::ufio::string str(10);

	::ufio::array<::ufio::io_scatter_t, 2> scat{::ufio::io_scatter_t{buffer.data(), buffer.size()}, ::ufio::io_scatter_t{str.data(), str.size()}};

	::ufio::operations::scatter_pread_all_bytes_span(nf, scat, 2);
	::ufio::io::println("buffer:", ::ufio::string_view(::ufio::freestanding::from_range, buffer),
						   "\nstr:", str);
}
