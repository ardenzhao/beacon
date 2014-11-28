/*
 * fcl.beacon project
 *
 * FILE test_algorithm.c
 * DATE 2013/08/29
 * AUTHOR Arden Zhao
 *
 * */

#include<stdio.h>
#include<stdlib.h>
#include"../algorithm/bc_algorithm.h"

int compare_double(const void* a, const void* b)
{
    return *(double*)a - *(double*)b;
}

void test_algorithm()
{
    double* data =(double*)malloc(5* sizeof(double));
    if(!data)
    {
	printf("BAD. no memory left. :(\n");
        return;
	}
    data[0] = 3; 
    data[1] = 8;
    data[2] = 4;
    data[3] = 6;
    data[4] = 7;
    int i =0;

    printf("before sort:\n");
    for(i =0; i< 5;i++)
        printf("%f ",data[i]);
    printf("\n");

    //sort((void*)data,5,sizeof(double),compare_double,NULL);
    sort_double(data,5); 
    printf("after sort:\n"); 
    for(i =0; i<5; i++)
    {
        printf("%f ",data[i]);
    }
    printf("\n");

    free(data);
}

