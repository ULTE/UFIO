#include <ufio_dsal/list.h>
#include <ufio.h>

int main()
{
	ufio::list<int> list1{5, 9, 1, 3, 3};
	ufio::list<int> list2{8, 7, 2, 3, 4, 4};

	list1.sort();
	list2.sort();
	println("list1:", ::ufio::mnp::rgvw(list1, " "), "\nlist2:",
			::ufio::mnp::rgvw(list2, " "));

	list1.merge(::std::move(list2));
	println("merged:", ::ufio::mnp::rgvw(list1, " "));
}