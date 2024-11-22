#include <algorithm>
#include <ranges>
#include <string>
#include <ufio.h>
#include <ufio_dsal/vector.h>
using namespace ufio::io;
using namespace ufio::mnp;

struct A
{
	std::string s;

	A(std::string str)
		: s(std::move(str))
	{
		print(" constructed\n");
	}

	A(A const &o) noexcept
		: s(o.s)
	{
		print(" copy constructed\n");
	}

	A(A &&o) noexcept
		: s(std::move(o.s))
	{
		print(" move constructed\n");
	}

	A &operator=(A const &other) noexcept
	{
		s = other.s;
		print(" copy assigned\n");
		return *this;
	}

	A &operator=(A &&other) noexcept
	{
		s = std::move(other.s);
		print(" move assigned\n");
		return *this;
	}
};

int main()
{
	ufio::vector<A> container;
	// reserve enough place so vector does not have to resize
	container.reserve(10);
	print("construct 2 times A:\n");
	A two{"two"};
	A three{"three"};

	print("emplace:\n");
	container.emplace(container.end(), "one");

	print("emplace with A&:\n");
	container.emplace(container.end(), two);

	print("emplace with A&&:\n");
	container.emplace(container.end(), std::move(three));

	println("content:\n ", rgvw(container | std::views::transform([](auto const &a) { return a.s; }), " "));
}
