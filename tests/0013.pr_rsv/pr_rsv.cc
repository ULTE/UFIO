#include <ufio.h>

using namespace ufio::io;

int main()
{
	char buffer[::ufio::pr_rsv_size<char, double>];
	auto i{::ufio::pr_rsv_to_c_array(buffer, 2.21421421412412214124124)};
	println("buffer size:", sizeof(buffer), "\ndata:", ufio::mnp::os_c_str(buffer, i));
}
