#include <ufio_dsal/string_view.h>
#include <ufio.h>

int main()
{
	static_assert(!::std::constructible_from<::ufio::cstring_view, ::ufio::string_view>);
	static_assert(::std::constructible_from<::ufio::string_view, ::ufio::cstring_view>);
	::ufio::cstring_view e;
	::ufio::cstring_view stvw("hello \0worldwoo");
	::ufio::string_view msv(stvw);
	char buffer[40];
	::ufio::io::println(stvw, ::ufio::mnp::os_c_str(e.c_str()), "\n",
						   stvw == msv,
						   stvw == "hello world\n", "\n",
						   "hello world\n" == stvw, "\n",
						   stvw <=> "hello world\n", "\n",
						   "hello world\n" <=> stvw, "\n",
						   stvw.starts_with("hello"), "\n",
						   stvw.ends_with("\0world\n"), "\n",
						   stvw.subview(5), "\n",
						   stvw.subview(5, 3), "\n",
						   stvw.find_character('w'), "\n",
						   stvw.find_character('a'), "\n",
						   stvw.find("\0world"), "\n",
						   stvw.rfind("wo"), "\n",
						   stvw.contains("world"), "\n",
						   ::ufio::string_view(buffer, stvw.copy(buffer, 6, 2)), "\n",
						   stvw.rfind_character('o'), "\n",
						   stvw.rfind_not_character('o'), "\n",
						   stvw.compare_three_way(0, 4, "hell", 4));
}
