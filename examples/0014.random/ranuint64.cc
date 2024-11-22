#include<random>
#include<ufio.h>

int main()
{
	::ufio::ibuf_white_hole_engine iwhe;
	::std::uniform_int_distribution<::std::uint_least64_t> udis(0,UINT_LEAST64_MAX);
	for(::std::size_t i{};i!=10;++i)
	{
		::ufio::io::println(::ufio::mnp::addrvw(udis(iwhe)));
	}
}

