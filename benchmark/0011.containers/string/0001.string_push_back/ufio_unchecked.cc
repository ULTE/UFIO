#include<ufio_dsal/string.h>
#include<ufio_driver/timer.h>

int main()
{
	::ufio::u8string str;
	::std::size_t total_sum{};
	{
		::ufio::timer t(u8"ufio_unchecked");
		constexpr ::std::size_t n{10000000u};
		str.reserve(n);
		for(::std::size_t i{};i!=n;++i)
		{
			str.push_back_unchecked(u8'z');
			total_sum+=str.size();
		}
	}
	::ufio::io::println(total_sum);
}
