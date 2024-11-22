#pragma once

#if !defined(__cplusplus)
#error "You are not using a C++ compiler"
#endif

#if !defined(__cpp_concepts)
#error "ufio requires at least C++20 standard compiler."
#else

#if ((__STDC_HOSTED__ == 1 && (!defined(_GLIBCXX_HOSTED) || _GLIBCXX_HOSTED == 1) && \
	  !defined(_LIBCPP_FREESTANDING)) ||                                             \
	 defined(UFIO_ENABLE_HOSTED_FEATURES))
#include "ufio_hosted.h"

#include "ufio_dsal/impl/misc/push_warnings.h"

#include "ufio_crypto/platforms/impl.h"

#endif

#include "ufio_dsal/impl/misc/pop_warnings.h"

#endif
