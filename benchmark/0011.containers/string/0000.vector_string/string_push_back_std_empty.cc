#include<string>
#include<ufio_dsal/vector.h>
#include<ufio_driver/timer.h>

int main()
{
	::ufio::vector<::std::u8string> vec;
	::std::size_t total_sum{};
	{
		::ufio::timer t(u8"string_push_back_std_empty");
		for(::std::size_t i{};i!=1000000u;++i)
		{
			total_sum+=vec.emplace_back().size();
		}
	}
	::ufio::io::println(total_sum);
}