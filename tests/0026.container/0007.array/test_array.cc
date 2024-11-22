#include <ufio_dsal/array.h>
#include <ufio.h>

int main()
{
	constexpr ::ufio::array<::std::size_t, 4> arr1{1, 4, 6, 8};
	constexpr ::ufio::array<::std::size_t, 7> arr2{1, 4, 6, 7, 10};
	constexpr ::ufio::array arr3{static_cast<::std::uint_least32_t>(3), 5, 6, 7, 8, 10};
	for (auto const &e : arr1)
	{
		::ufio::io::println(e);
	}
	for (auto const &e : arr2)
	{
		::ufio::io::println(e);
	}
	::ufio::io::println(arr1 <=> arr2);

	for (::std::size_t i{}; i != arr1.size(); ++i)
	{
		::ufio::io::println(arr1[i]);
	}
	for (::std::size_t i{}; i != arr2.size(); ++i)
	{
		::ufio::io::println(arr2[i]);
	}
	::ufio::io::println(arr1 <=> arr2);

	for (auto const &e : arr3)
	{
		::ufio::io::println(e);
	}
}
