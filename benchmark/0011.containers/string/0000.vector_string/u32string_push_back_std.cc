#include<string>
#include<ufio_dsal/vector.h>
#include<ufio_driver/timer.h>

int main()
{
	::ufio::vector<::std::u32string> vec;
	::std::size_t total_sum{};
	{
		::ufio::timer t(u8"string_push_back_std");
		for(::std::size_t i{};i!=1000000u;++i)
		{
			total_sum+=vec.emplace_back(U"hello world\n").size();
		}
	}
	::ufio::io::println(total_sum);
}