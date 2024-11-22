#include <ufio_dsal/deque.h>
#include <ufio.h>

int main()
{
	::ufio::deque<int> deq;

	for (int i{}; i != 1000000; ++i)
	{
		deq.push_front(i);
		deq.push_back(i);
	}
	::ufio::io::println(deq.size());
}
