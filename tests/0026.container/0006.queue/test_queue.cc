#include <ufio_dsal/queue.h>
#include <cstddef>
#include <ufio.h>

int main()
{
	::ufio::queue<::std::size_t> queue;
	queue.push(40);
	queue.push(60);
	::ufio::io::println(queue.pop_element());
}
