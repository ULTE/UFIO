/*
This is an example to explain why address sanitizers suck
*/
#include <ufio.h>
#include <ufio_dsal/string_view.h>
#include <ufio_dsal/string.h>

int main()
{
	ufio::string str("helloworld");
	ufio::string_view vw(str.subview(3, 4));
	using namespace ::ufio::io;
	println("before replace:", str, "\n", vw);
	str.replace_index(1, 5, vw);
	// dangling string_view
	println("after replace:", str, "\n", vw); // asan cannot detect this, but my secrect tool can lol
}
