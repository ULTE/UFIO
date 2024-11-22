#include <ufio_dsal/stack.h>
#include <cstddef>
#include <ufio.h>

int main()
{
	::ufio::stack<::std::size_t> stack;
	stack.push(40);
	stack.push(60);
	::ufio::io::println(stack.pop_element());
}
