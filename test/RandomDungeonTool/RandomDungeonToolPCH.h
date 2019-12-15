#pragma once

// workaround for 'TryEnterCriticalSection' compile error
#ifdef _WIN32
#  ifndef _WIN32_WINNT
#    define _WIN32_WINNT 0x400
#  endif
#endif
// Exclude rarely-used stuff from Windows headers
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

// Gideon
#include <gideon/cs/Common.h>

// https://github.com/boostorg/random/issues/49#issuecomment-450601746
#define BOOST_ALLOW_DEPRECATED_HEADERS
