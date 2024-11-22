#include <ufio.h>
#include <ufio_dsal/array.h>
#include <ufio_dsal/string_view.h>
#include <ufio_dsal/span.h>
#include <ufio_device.h>

int main()
{
	::ufio::obuf_file nf(u8"wsme.txt");

	constexpr ::ufio::string_view view1("Hello World\n");
	constexpr ::ufio::string_view view2("Do something\n");

	::ufio::array scat{::ufio::io_scatter_t{view1.data(), view1.size()}, ::ufio::io_scatter_t{view2.data(), view2.size()}};

	::ufio::operations::scatter_write_all_bytes_span(nf, scat);
	constexpr ::ufio::string_view view("Goodby, Cruel World\n");
	::ufio::operations::write_all_span(nf, ::ufio::span(view));

	constexpr ::ufio::string_view view4("Yes, Offset World\n");
	::ufio::operations::pwrite_all_span(nf, ::ufio::span(view1), 10);
	::ufio::operations::scatter_pwrite_all_bytes_span(nf, scat, 30);
}
