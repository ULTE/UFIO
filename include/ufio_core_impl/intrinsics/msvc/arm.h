#pragma once

namespace ufio::intrinsics::msvc::arm
{

extern "C"
{
	unsigned __int64 __getReg(int);

	unsigned int _MoveFromCoprocessor(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);

}

} // namespace ufio::intrinsics::msvc::arm
