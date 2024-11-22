#include <ufio_dsal/vector.h>
#include <ufio.h>
#include <memory>

namespace ufio::freestanding
{

template <typename T>
struct is_trivially_relocatable<::std::shared_ptr<T>>
{
	static inline constexpr bool value = true;
};

} // namespace ufio::freestanding

int main()
{
	::ufio::vector<::std::shared_ptr<int>> vec{std::make_shared<int>(1), std::make_shared<int>(2), std::make_shared<int>(3)};
	vec.insert_index(1, std::make_shared<int>(4));
	using namespace ::ufio::io;
	print("After vec.insert_index(1)\n");
	for (auto const &e : vec)
	{
		println(::ufio::mnp::pointervw(e.get()), " use_count: ", e.use_count());
	}
	vec.erase_index(0, 2);
	print("After vec.erase_index(0,2)\n");
	for (auto const &e : vec)
	{
		println(::ufio::mnp::pointervw(e.get()), " use_count: ", e.use_count());
	}
}
