#include <ufio.h>

int main()
{
	::ufio::u8iobuf_io_file file(::ufio::io_cookie_type<::ufio::u8native_file>, u8"io_file.txt", ::ufio::open_mode::out);

	using namespace ::ufio::io;

	print(file, u8"Hello World\n", u8"14214", u8"\nHello World\n", u8"asfasfs");
	print(file, u8"Hello World\n", u8"14214", u8"\nHello World\n");
	print(file, u8"Hello World\n", u8"14214", u8"\nHello World\n", u8"124");
	print(file, u8"Hello World\n", u8"14214", u8"\nHello World\n", u8"asfasfasf", u8"asgasgasg");
	print(file, u8"Hello World\n", u8"14214", u8"\nHello World\n", u8"asfasfasf", u8"asgasgasg", u8"2632");
	print(file, u8"Hello World\n", u8"14214", u8"\nHello World\n", u8"asfasfasf", u8"asgasgasg", u8"2632", u8"1235");
	print(file, u8"Hello World\n", u8"14214", u8"\nHello World\n", u8"asfasfasf", u8"asgasgasg", u8"2632", u8"1235", u8"safas");
	print(file, u8"Hello World\n", u8"14214", u8"\nHello World\n", u8"asfasfasf", u8"asgasgasg", u8"2632", u8"1235", u8"safas", u8"asfasfsafasfsa\n");
}
