#include <ufio.h>

using namespace ufio::io;

int main()
{
	ufio::c_file cfl("c_file.txt", ufio::open_mode::out);
	/*
	c_file will construct a FILE* directly through syscalls.
	*/
	print(cfl, "Hello World from ufio::c_file\n");
	/*
	Just for demo purpose
	This is dangerous. use fprintf to print string is awful.
	*/
	[[maybe_unused]] auto _ = std::fprintf(cfl.fp, "Hello World from FILE* danger\n");
	[[maybe_unused]] auto __ = std::fprintf(cfl.fp, "%s", "Hello World from FILE* safe\n");
}
