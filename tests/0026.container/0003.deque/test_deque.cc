#include <ufio_dsal/deque.h>
#include <ufio.h>

int main()
{
	::ufio::deque<int> dq;
	dq.push_back(4);
	dq.push_back(6);
	static_assert(::std::random_access_iterator<decltype(dq.begin())>);
	::ufio::io::println("diff:", dq.end() - dq.begin());
	for (auto const &e : dq)
	{
		::ufio::io::println(e);
	}
}
