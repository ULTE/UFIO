#include <string>
#include <ufio.h>

int main()
{
	::std::string str("asfasfjaspofjaspofajsfpoasfsaf");
	::ufio::details::string_hack::set_end_ptr(str, str.data() + 5); // resize to 5
}