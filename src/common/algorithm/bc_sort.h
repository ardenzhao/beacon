/*
 * fcl.beacon project
 *
 * FILE bc_sort.h
 * DATE 2013/08/28
 * AUTHOR Arden Zhao
 *
 * */
#ifndef __BC_SORT_H__
#define __BC_SORT_H__

#include<stdlib.h>

/*
 * HEAP SORT refer to GLS implementation and Matt Mackall <mpm@selenic.com>
 * */
void sort( void* data, size_t size, size_t size_of_type,
          int (*compare_function)(const void*, const void*),
          void(*swap_function)(void*,void*,const size_t size));

void sort_double(double* data, size_t size);

#endif /* __BC_SORT_H__ */

