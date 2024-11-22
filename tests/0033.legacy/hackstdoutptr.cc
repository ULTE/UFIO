#include <ufio.h>

int main()
{
	using namespace ufio::mnp;
	using namespace ufio::io;
	::ufio::c_io_observer_unlocked ciob{stdout};
	for(::std::size_t i{};i!=100000u;++i)
	{
		perrln(ciob,pointervw(obuffer_begin(ciob)), " ", pointervw(obuffer_curr(ciob)), " ", pointervw(obuffer_end(ciob)));
		println(40);
		perrln(ciob,pointervw(obuffer_begin(ciob)), " ", pointervw(obuffer_curr(ciob)), " ", pointervw(obuffer_end(ciob)));
	}
}
