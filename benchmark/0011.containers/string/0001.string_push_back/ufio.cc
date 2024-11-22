#include<ufio_dsal/string.h>
#include<ufio_driver/timer.h>

int main()
{
	::ufio::u8string str;
	::std::size_t total_sum{};
	{
		::ufio::timer t(u8"ufio");
		for(::std::size_t i{};i!=10000000u;++i)
		{
			str.push_back(u8'z');
			total_sum+=str.size();
		}
	}
	::ufio::io::println(total_sum);
}
