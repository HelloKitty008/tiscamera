
#ifndef image_transform_interop_h_
#define image_transform_interop_h_

#pragma once

#ifdef KERNEL_DRIVER_

#include <wdm.h>
#include <windef.h>

#include "../dutils/base/base_types.h"

using namespace dutil::types;


#pragma warning ( disable : 4201 )
#pragma warning ( disable : 4127 ) // conditional expression is constant

#if !defined assert && defined ASSERT
#define assert ASSERT
#endif

#else

// these must be replaced in a driver context
#include <cstring>
#include <cstdint>
#include <assert.h>
#include <cstdlib>

typedef uint8_t byte;

#ifndef ASSERT
#define ASSERT assert
#endif

#ifndef _WINDOWS_
typedef struct tagPOINT
{
	int	x;
	int	y;
} POINT, *PPOINT, *LPPOINT;
typedef struct tagRECT
{
	int left;
	int top;
	int right;
	int bottom;
} 	RECT;
typedef struct tagSIZE
{
    int     cx;
    int     cy;
} SIZE, *PSIZE, *LPSIZE;

/* sal defines */
#ifndef __inout_bcount
#define __inout_bcount( x )
#define __in_bcount( x )
#define __inout_ecount( x )
#define __in_ecount( x )
//#define __in
//#define __out
//#define __inout
#endif

#endif

#endif

// we need to use uppercase because some stdlib stuff in gcc headers is not guarded against this
#ifndef MIN
#define MIN(x,y) (((x) < (y)) ? (x) : (y))
#endif
#ifndef MAX
#define MAX(x,y) (((x) > (y)) ? (x) : (y))
#endif

#ifndef C_ASSERT
#define C_ASSERT(e) typedef char __C_ASSERT__[(e)?1:-1]
#endif

#ifndef UNREFERENCED_PARAMETER
#define UNREFERENCED_PARAMETER(x) (x)
#endif

#if defined(_MSC_VER)
#define _ALIGNED(x) __declspec(align(x))
#define FORCEINLINE    __forceinline
#elif defined(__GNUC__)
#define FORCEINLINE __attribute__((always_inline)) inline
#define _ALIGNED(x) __attribute__ ((aligned(x)))

#pragma GCC diagnostic ignored "-Wattributes"

#endif

#define SSE_ALIGN   _ALIGNED(16)

#endif // image_transform_interop_h_


