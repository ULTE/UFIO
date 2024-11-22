﻿#include <string>
#include <ufio.h>

using namespace ufio::io;

int main()
{
	std::string s1{"2022-12-01T01:23:45.0000000000000000002500000000000000000000-00:00"};
	println(s1);
	auto tsp1 = ufio::to<ufio::iso8601_timestamp>(s1);
	println(tsp1);
	std::string s2{"2022-12-01T01:23:45.0000000000000000002500000000000000000000000001+00:00"};
	println(s2);
	auto tsp2 = ufio::to<ufio::iso8601_timestamp>(s2);
	println(tsp2);
	std::string s3{"2022-12-01T01:23:45.000000000000000000350000000000000000000000000000000Z"};
	println(s3);
	auto tsp3 = ufio::to<ufio::iso8601_timestamp>(s3);
	println(tsp3);
}