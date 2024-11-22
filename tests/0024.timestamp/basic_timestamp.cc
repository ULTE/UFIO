#include <string>
#include <ufio.h>

using namespace ufio::io;

int main()
{
	auto tsp1 = ufio::to<ufio::win32_timestamp>("1231232.23423423423423423435");
	auto tsp2 = ufio::to<ufio::win32_timestamp>("1", "2", "3", "1", "2", "3", "2", ".", "2", "3", "4", "2", "3", "4", "2", "3", "4", "2", "3", "4", "2", "3", "4", "2", "3", "4", "3", "5");
	println("tsp1 == tsp2: ", ufio::mnp::boolalpha(tsp1 == tsp2));
	auto s = ufio::concat_std(tsp1);
	println("is scan correct: ", ufio::mnp::boolalpha(s == "11645704832.2342342342342342344"));
}