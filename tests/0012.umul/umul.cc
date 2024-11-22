#include <ufio.h>

using namespace ufio::io;

int main()
{
	std::uint64_t high;
	std::uint64_t low = ufio::details::intrinsics::umul(7941694176621304320ULL, 11235582092889474423ULL, high);
	print(low, " ", high);
}
