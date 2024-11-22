#include <winrt/base.h>
#include <ufio.h>

using namespace ufio::io;

int main()
{
	winrt::hstring hstr;
	scan(ufio::mnp::strlike_get(hstr));
	println(hstr);
}
