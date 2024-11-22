#include <ufio_dsal/list.h>
namespace test
{
template <typename T>
using list = ::ufio::list<T>;
}
/*
Unfortunately ufio internally sometimes uses list despite i try to avoid them. Well then better expose the APIs
*/
#define BENCH_LIST_COMMENT_STRING u8"ufio::list<T>"
#include "main.h"
