#include <ufio_dsal/vector.h>
namespace test
{
template <typename T>
using vector = ::ufio::vector<T>;
}
/*
Unfortunately ufio internally sometimes uses vector despite i try to avoid them. Well then better expose the APIs
*/
#define BENCH_VECTOR_COMMENT_STRING u8"ufio::vector<T>"
#include "main.h"
