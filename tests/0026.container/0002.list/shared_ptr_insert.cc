#include <ufio_dsal/list.h>
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
	::ufio::list<::std::shared_ptr<int>> lst{std::make_shared<int>(1), std::make_shared<int>(2), std::make_shared<int>(3)};
	lst.insert(lst.cbegin(), std::make_shared<int>(4));
	for (auto const &e : lst)
	{
		::ufio::io::println(::ufio::mnp::pointervw(e.get()), " use_count: ", e.use_count());
	}
}
