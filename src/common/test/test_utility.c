/*
 * fcl.beacon project
 *
 * FILE test_utility.c
 * DATE 2013/08/30
 * AUTHOR Arden Zhao
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include "../utility/bc_utility.h"

void test_utility()
{
    double array[] = {1,2,3,4,5};
    double *new_array = NULL;
    double *resize_array = NULL;
    int i;

    //PRINT ORIGINAL ARRAY
    printf("start testing beacon utility functions\n");
    printf("original array is:\n");
    for(i=0; i<5; i++)
    {
        printf("%f\t",array[i]);
    }
    printf("\n");

    //ARRAY_SIZE:
    size_t size = ARRAY_SIZE(array); 
    printf("size of array: %d\n", (int)size);
    
    //ARRAY_CREATE:
    new_array = ARRAY_CREATE(double, size);

    //ARRAY_COPY:
    ARRAY_COPY(new_array, array, size);
    
    printf("new array is:\n");
    for(i=0;i<size;i++)
    {
        printf("%f\t",new_array[i]);
    }
    printf("\n");
    
    //ARRAY_RESIZE:
    resize_array = ARRAY_RESIZE( new_array, 10);
    if(resize_array != NULL)
    {

        printf("before resize array address: %p\n", new_array);
        new_array = resize_array;
        printf("resize array address: %p\n", resize_array);
    }
    //ARRAY_DELETE:
    ARRAY_DELETE(new_array);    

}
