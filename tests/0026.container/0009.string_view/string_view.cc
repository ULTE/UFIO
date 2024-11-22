#include <ufio_dsal/string_view.h>
#include <ufio.h>

int main()
{
	::ufio::string_view stvw("hello \0world\n");
	::ufio::io::println(stvw,
						   stvw == "hello world\n", "\n",
						   "hello world\n" == stvw, "\n",
						   stvw <=> "hello world\n", "\n",
						   "hello world\n" <=> stvw, "\n",
						   stvw.starts_with("hello"), "\n",
						   stvw.ends_with("\0world\n"));
}