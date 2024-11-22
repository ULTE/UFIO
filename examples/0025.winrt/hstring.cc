#include <winrt/base.h>
#include <ufio.h>

using namespace ufio::io;

int main()
{
	println(ufio::wconcat_winrt_hstring(L"qqwdwq", 1234, L"asfasf"));
}
