#pragma once

/*
ugly hack against standard bug
https://gcc.gnu.org/bugzilla/show_bug.cgi?id=111353
*/

namespace ufio::freestanding
{

using ::std::allocator;

}
