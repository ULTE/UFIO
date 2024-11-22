#include <string>
#include <ufio.h>
#include <cassert>

constexpr bool foo()
{
	std::string str{ufio::concat_std("abcwe")};
	std::string str2{"abcwe"};
	return str == str2;
}

static_assert(foo());

int main()
{
	assert(foo());
}