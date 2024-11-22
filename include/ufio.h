#pragma once
#if !defined(__cplusplus)
#error "You are not using a C++ compiler"
#endif

#if !defined(__cpp_concepts)
#error "ufio requires at least C++20 standard compiler."
#else

#include "ufio_hosted.h"

#include "ufio_dsal/impl/misc/push_warnings.h"

#include "ufio_legacy_impl/io.h"

#include "ufio_dsal/impl/misc/pop_warnings.h"

#endif
