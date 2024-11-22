#if 0
#include <ufio_dsal/forward_list.h>
#include <ufio.h>
using namespace ufio::io;
using namespace ufio::mnp;
#endif

int main()
{
#if 0
	::ufio::forward_list<::std::size_t> lst;
	for (::std::size_t i{}; i != 10; ++i)
	{
		lst.push_front(i);
	}
	println("lst:\n", ::ufio::mnp::rgvw(lst, "\n"),
			"\nfront:", lst.front());
	::ufio::forward_list<::std::size_t> lst2(lst);
	lst2.splice_before_after(lst2.cbefore_begin(), lst.cbefore_begin(), lst.cbegin());
	lst2.splice_before_after(lst2.cbefore_begin(), lst.cbefore_begin(), lst.cbefore_begin());
	lst.erase_after(lst.cbefore_begin(), lst.cbegin());
	lst.pop_front();
	println("lst2:\n", ::ufio::mnp::rgvw(lst2, "\n"),
			"\nlst after operations:\n", ::ufio::mnp::rgvw(lst, "\n"),
			// unfinished
			"\nlst is empty? ", lst.empty(), "\n"
											 "lst2 is empty? ",
			lst2.is_empty(), "\n"
							 "lst<=>lst2:",
			lst <=> lst2);
#endif
}
