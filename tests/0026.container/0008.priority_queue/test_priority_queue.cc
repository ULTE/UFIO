#include <ufio_dsal/priority_queue.h>
#include <cstddef>
#include <ufio.h>

int main()
{
	::ufio::priority_queue<::std::size_t> pqueue;
	pqueue.push(40);
	pqueue.push(60);
	pqueue.push(70);
	pqueue.push(20);
	pqueue.push(15);
	::ufio::io::println(pqueue.pop_element());
}

