#include <ufio.h>

int main(int argc, char** argv)
{
for(int i = 0; i != argc; ++i)
{
	::ufio::io::perrln(::ufio::mnp::os_c_str(argv[i]));
}
}
