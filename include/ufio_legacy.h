#pragma once
#if !defined(__cplusplus)
#error "You are not using a C++ compiler"
#endif

#if !defined(__cpp_concepts)
#error "ufio requires at least C++20 standard compiler."
#else
// ufio_legacy.h deals with legacy C++ <iostream>/<fstream>/<sstream> interface
#if ((__STDC_HOSTED__ == 1 && (!defined(_GLIBCXX_HOSTED) || _GLIBCXX_HOSTED == 1) && \
	  !defined(_LIBCPP_FREESTANDING)) ||                                             \
	 defined(UFIO_ENABLE_HOSTED_FEATURES))

#include "ufio_dsal/impl/misc/push_warnings.h"

#include <streambuf>
#include <fstream>
#include <sstream>

#if 1
#include "ufio.h"
#else
#include "ufio_hosted.h"
#include "ufio_legacy_impl/c/impl.h"
#endif

#include "ufio_legacy_impl/filebuf/streambuf_io_observer.h"
#if !defined(_LIBCPP_HAS_NO_FILESYSTEM) || defined(_LIBCPP_HAS_FSTREAM)
#include "ufio_legacy_impl/filebuf/filebuf_file.h"
#endif
#include "ufio_legacy_impl/filebuf/op_out.h"

#include "ufio_dsal/impl/misc/pop_warnings.h"

#endif

#endif
