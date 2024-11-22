#include <ufio_legacy.h>

using namespace ufio::io;

int main()
{
	ufio::filebuf_file fbf(u8"filebuf_file_ostream.txt", ufio::open_mode::out);
	/*
	filebuf_file will construct a std::filebuf directly through syscalls.
	*/
	std::ostream fout(fbf.fb); // make std::ostream's streambuf binds to our filebuf_file
	print(fbf, "Hello World from ufio::filebuf_file\n");
	fout << "Hello World from std::ostream\n";
}
