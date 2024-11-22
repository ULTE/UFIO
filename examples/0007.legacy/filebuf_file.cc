#include <ufio_legacy.h>

using namespace ufio::io;

int main()
{
	ufio::filebuf_file fbf("filebuf_file.txt", ufio::open_mode::out);
	/*
	filebuf_file will construct a std::filebuf directly through syscalls.
	*/
	std::ofstream fout;
	*fout.rdbuf() = std::move(*fbf.fb); // move resource to std::ofstream

	ufio::filebuf_io_observer fiob{fout.rdbuf()};
	// because we moved the resources to fstream, we need to use filebuf_io_observer to use it instead
	print(fiob, "Hello World from ufio::filebuf_io_observer\n");
	fout << "Hello World from std::ofstream\n";
}
