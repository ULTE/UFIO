#include <string>
#include <ufio.h>
#include <ufio_device.h>
#include <ufio_dsal/string.h>

using namespace ::std::string_literals;

struct point
{
	int x{};
	int y{};
};

template <typename char_type, typename output>
void print_define(::ufio::io_reserve_type_t<char_type, point>, output out, point const &p)
{
	if constexpr (::std::is_same_v<char_type, char>)
	{
		::ufio::println(out, "(", p.x, ",", p.y, ")");
	}
}

int main()
{
	::ufio::println("Hello world!");
	::ufio::string str{"string"};
	::ufio::println(str);
	::ufio::println(::ufio::mnp::os_c_str(str.data()));
	::ufio::println(::ufio::mnp::pointervw(&str));
	::ufio::println(::ufio::mnp::rgvw(str, ","));
	::ufio::println(::ufio::mnp::chvw('c'));
	::ufio::println('c'); // output : 99
	::ufio::println(point{2, 5});

	::std::string s;
	::ufio::scan(::ufio::mnp::line_get(s));
	::ufio::println(s);

	return 0;
}
