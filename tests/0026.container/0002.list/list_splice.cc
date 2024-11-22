#include <ufio.h>
#include <ufio_dsal/list.h>
#include <iterator>

int main()
{
	ufio::list<int> list1{1, 2, 3, 4, 5};
	ufio::list<int> list2{10, 20, 30, 40, 50};

	auto it = list1.begin();
	std::advance(it, 2);

	list1.splice(it, std::move(list2));

	::ufio::println("list1:", ::ufio::mnp::rgvw(list1, " "), "\nlist2:",
			::ufio::mnp::rgvw(list2, " "));

	list2.splice(list2.begin(), it, list1.end());

	::ufio::println("list1:", ::ufio::mnp::rgvw(list1, " "), "\nlist2:",
			::ufio::mnp::rgvw(list2, " "));

	list2.splice(list2.cbegin(), list1.cbegin(), list1.cbegin());

	::ufio::println("list1:", ::ufio::mnp::rgvw(list1, " "), "\nlist2:",
			::ufio::mnp::rgvw(list2, " "));
}

