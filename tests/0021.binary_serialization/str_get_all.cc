#include <string>
#include <string_view>
#include <bit>
#include <ufio.h>
#include <ufio_device.h>

using namespace ufio::io;

int main()
{
	using namespace ufio::mnp;
	{
		ufio::obuf_file obf(u8"a.txt");
		std::string_view vw("sdgjasdopigjadsopgjdaspogjadspogjadspog");
		println("written size:", vw.size());
		print(obf, le_put<32>(vw.size()), vw);
	}
	std::string str;
	{
		ufio::ibuf_file ibf(u8"a.txt");
		std::size_t u;
		scan(ibf, le_get<32>(u), str_get_all(str, u));
	}
	println("size=", str.size(), "\n", str);
}
