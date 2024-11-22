#include <ufio.h>
#include <ufio_driver/openssl_driver.h>

using namespace ufio::io;

int main()
{
	ufio::bio_file bf("bio.txt", ufio::open_mode::out);
	print(bf, "Hello World to bio from ufio\n");
	BIO_printf(bf.bio, "hello %s\n", "world from openssl bio");
}
