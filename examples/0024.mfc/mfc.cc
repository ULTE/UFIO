#include <string>
#include <atlstr.h>
#include <ufio_driver/mfc.h>
#include <ufio.h>

using namespace ufio::io;

int main()
{
	CString cstr(ufio::concat_atl_cstring("wwadqwjdqwjopdqjdpoqwjdpqowdjqwpodjwqop ", 241.42315235, " asfaf"));
	print(cstr);
}
