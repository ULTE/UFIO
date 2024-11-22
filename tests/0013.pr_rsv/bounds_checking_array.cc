#include <array>
#include <ufio.h>

using namespace ufio::io;

int main()
{
	std::array<char, 20> buffer;
	// this would fail to compile
	auto i{::ufio::pr_rsv_to_array(buffer, ufio::mnp::scientific(2.21421421412412214124124))};
	println("buffer size:", buffer.size(), "\ndata:", ufio::mnp::os_c_str(buffer.data(), i));
}
