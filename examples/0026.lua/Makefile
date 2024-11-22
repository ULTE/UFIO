SYSROOT = $(HOME)/cross/wasm32-wasi
WASM2LUA = wasm2lua
CXX = clang++
LUAJIT = luajit

hello_ufio.lua:hello_ufio
	$(WASM2LUA) hello_ufio hello_ufio.lua -m, --minify 3
hello_ufio:hello_ufio.cc
	$(CXX) -o hello_ufio hello_ufio.cc -Ofast -std=c++2b -s -flto -fuse-ld=lld -I../../include -fno-exceptions -fno-rtti -fno-unwind-tables -fno-asynchronous-unwind-tables -fno-ident --target=wasm32-wasi --sysroot=$(SYSROOT)
run:main.lua hello_ufio.lua wasilib.lua
	luajit main.lua
clean:
	rm hello_ufio hello_ufio.lua
