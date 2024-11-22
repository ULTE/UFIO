﻿#include<ufio_dsal/vector.h>
#include<ufio_dsal/string.h>
#include<ufio_driver/timer.h>

int main()
{
	::ufio::vector<::ufio::u8string> vec;
	::std::size_t total_sum{};
	{
		::ufio::timer t(u8"string_push_back_ufio_empty");
		for(::std::size_t i{};i!=1000000u;++i)
		{
			total_sum+=vec.emplace_back().size();
		}
	}
	::ufio::io::println(total_sum);
}