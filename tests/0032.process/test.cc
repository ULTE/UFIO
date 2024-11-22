#include <ufio.h>

int main()
{
	::ufio::io::perr("hello\n");
	::ufio::native_file o{u8"test.txt", ::ufio::open_mode::out};

	::ufio::io::perr(o, "hello\n");
}
