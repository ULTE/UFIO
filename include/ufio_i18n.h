#pragma once
#if !defined(__cplusplus)
#error "You are not using a C++ compiler"
#endif

#if !defined(__cpp_concepts)
#error "ufio requires at least C++20 standard compiler."
#else
#include "ufio_hosted.h"

#include "ufio_dsal/impl/misc/push_warnings.h"

#include "ufio_i18n/lc.h"
#include "ufio_i18n/lc_print.h"
#if ((__STDC_HOSTED__ == 1 && (!defined(_GLIBCXX_HOSTED) || _GLIBCXX_HOSTED == 1) && \
	  !defined(_LIBCPP_FREESTANDING)) ||                                             \
	 defined(UFIO_ENABLE_HOSTED_FEATURES))
#include "ufio_i18n/locale/impl.h"
#endif
#include "ufio_i18n/imbuer.h"
#include "ufio_i18n/lc_status_print.h"
#include "ufio_i18n/lc_numbers/impl.h"

#if ((__STDC_HOSTED__ == 1 && (!defined(_GLIBCXX_HOSTED) || _GLIBCXX_HOSTED == 1) && \
	  !defined(_LIBCPP_FREESTANDING)) ||                                             \
	 defined(UFIO_ENABLE_HOSTED_FEATURES))
#if defined(_GLIBCXX_STRING) || defined(_LIBCPP_STRING) || defined(_STRING_)
#include "ufio_unit/string.h"
#include "ufio_unit/string_impl/lc_concat.h"
#endif
#endif

#ifndef UFIO_DISABLE_FLOATING_POINT
#include "ufio_unit/floating/lc_impl.h"
#endif

#include "ufio_dsal/impl/misc/pop_warnings.h"

#endif
