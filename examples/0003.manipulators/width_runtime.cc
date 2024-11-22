﻿#include <ufio.h>

using namespace ufio::io;

int main()
{
	using namespace ufio::mnp;
	scalar_placement place1 = scalar_placement::left;
	scalar_placement place2 = scalar_placement::middle;
	scalar_placement place3 = scalar_placement::right;
	scalar_placement place4 = scalar_placement::internal;
	println(width(place1, "hello", 20), "\n", width(place2, "hello", 20), "\n", width(place3, "hello", 20, '0'), "\n",
			width(place4, "hello", 20), "\n", width(place4, dfvw(4), 20));
}
/*
D:\hg\ufio\examples\0003.manipulators>g++ -o width_runtime width_runtime.cc -Ofast -std=c++23 -s -flto -march=native
-I../../include

D:\hg\ufio\examples\0003.manipulators>width_runtime
hello
	   hello
000000000000000hello
			   hello
+         0x00000004
*/
