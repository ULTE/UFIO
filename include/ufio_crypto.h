#pragma once

// ufio_crypto.h defines what you could use for cryptography
// It is likely usable in a freestanding environment
#if !defined(__cplusplus)
#error "You are not using a C++ compiler"
#endif

#if !defined(__cpp_concepts)
#error "ufio requires at least C++20 standard compiler."
#else

#include "ufio_core.h"

#include "ufio_dsal/impl/misc/push_warnings.h"

// #include"ufio_crypto/symmetric_crypto.h"
// #include"ufio_crypto/hash/intrin_include.h"
#include "ufio_crypto/hash/impl.h"

#include "ufio_dsal/impl/misc/pop_warnings.h"

#endif
