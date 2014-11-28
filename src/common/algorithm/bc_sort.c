/*
 * fcl.beacon project
 *
 * FILE bc_sort.h
 * DATE 2013/08/28
 * AUTHOR Arden Zhao
 *
 **/

#include <stdlib.h>
#include "bc_sort.h"

static inline void swap( void* a, void* b, const size_t size);
static inline void swap_double(void* a, void* b, const size_t size);

static inline void swap( void* a, void* b, const size_t size)
{
    register char tmp;
    register size_t s = size;

    if(a == b)
        return;

    do
    {
        tmp = *(char*)a;
        *(char*)a++ = *(char*)b;
        *(char*)b++ = tmp;
    }while(--s > 0);
}

static inline void swap_double(void* a, void*b, const size_t size)
{
    register double tmp;
    register size_t s = size;
    
    if(a == b)
        return;
    
    tmp = *(double*)a;
    *(double*)a = *(double*)b;
    *(double*)b = tmp;
  
}

void sort(void* data, size_t size, size_t size_of_type,
          int (*compare_function)(const void*, const void*),
          void (*swap_function)(void*, void*, const size_t size))
{
    int i = (size/2-1) * size_of_type;
    int n = size * size_of_type;
    int c, r;

    if(!swap_function)
	swap_function = swap;

    /* heapify */
    for( ; i >=0; i -= size_of_type)
    {
        for( r = i; r *2 + size_of_type < n; r = c)
        {
            c = r * 2 + size_of_type;
            if ( c < n - size_of_type && 
                 compare_function(data + c, data + c + size_of_type) < 0)
            {
                 c += size_of_type;
            }
            if ( compare_function( data + r, data + c) >= 0)
            {
                break;
            }
            swap_function(data + r, data + c, size_of_type);
        }
    }
    
    /* sort */
    for ( i = n - size_of_type; i > 0; i -= size_of_type)
    {
        swap_function( data, data + i, size_of_type);
        for( r = 0; r * 2 + size_of_type < i; r = c)
        {
            c = r * 2 + size_of_type;
            if( c < i - size_of_type &&
                compare_function(data + c, data + c + size_of_type) < 0 )
            {
                c += size_of_type;
            }
            if( compare_function(data + r, data + c) >= 0 )
            {
                break;
            }
            swap_function(data + r,  data + c, size_of_type);
        }
    }
}

static inline int compare_double(const void* a, const void*b)
{
    return *(double*)a- *(double*)b;
}

void sort_double(double* data, const size_t size)
{
     sort((void*)data, size, sizeof(double),compare_double,swap_double);
}

