#include<string>
#include<ufio_driver/timer.h>

int main()
{
	::std::u8string str;
	::std::size_t total_sum{};
	{
		::ufio::timer t(u8"std");
		for(::std::size_t i{};i!=10000000u;++i)
		{
			str.push_back(u8'z');
			total_sum+=str.size();
		}
	}
	::ufio::io::println(total_sum);
}
