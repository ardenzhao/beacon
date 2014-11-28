/*
 * fcl.beacon project
 *
 * FILE bc_utility.h
 * DATE 2013/08/30
 * AUTOHR Arden Zhao
 *
 * */
#ifndef __BC_UTILITY_H
#define __BC_UTILITY_H

#include <stdlib.h>
#include <string.h>

// MACRO TO PLAY ARRAY
#define ARRAY_SIZE(array) (sizeof (array) / sizeof (array[0]) )
#define ARRAY_COPY(dst, src, cnt) memcpy( (void*)(dst), (void*)(src), (cnt)* sizeof((src)[0]) )
#define ARRAY_CREATE( type, cnt) (type*)malloc( (cnt)* sizeof(type))
#define ARRAY_DELETE(array) free( (void*) (array))
#define ARRAY_RESIZE(array, size) realloc( (void*)(array), (size)*sizeof( (array)[0] ) )

#endif
