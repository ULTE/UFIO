#if defined(USE_STD)
#include <vector>
#include <cstdint>
namespace test
{
template <typename T>
using vector = ::std::vector<T>;
}
#else
#include <ufio_dsal/vector.h>

namespace test
{
template <typename T>
using vector = ::ufio::vector<T>;
}
#endif

/*
Unfortunately ufio internally sometimes uses vector despite i try to avoid them. Well then better expose the APIs
*/

int main()
{
	test::vector<test::vector<std::int_least32_t>> vec1(1000);
	test::vector<test::vector<char32_t>> vec2;
}