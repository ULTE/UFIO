#include <ufio.h>

using namespace ufio::io;

int main()
{
	print(ufio::out(), "Hello Lua World from C++ 23 ufio library. Thank to wasm2lua!\n");
#if 0
	print("Hello Lua World from C++ 23 ufio library. Thank to wasm2lua!\n");
/*	
	will cause out of memory access. need to report bugs
luajit: hello_ufio.lua:1: out of memory access
stack traceback:
        [C]: in function 'assert'
        hello_ufio.lua:1: in function 'al'
        hello_ufio.lua:1: in function '_start'
        main.lua:8: in main chunk
        [C]: at 0x5652a18d41d0
*/
#endif
}
