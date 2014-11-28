/*
 * fcl.beacon project
 *
 * FILE test_common.c
 * DATE 2013/11/14
 * AUTHOR Arden Zhao
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include "test_common.h"

extern void test_statistic();
extern void test_algorithm();
extern void test_utility();

int main()
{
    //TEST STATISTIC
    printf("----------------------------\n");
    printf("\t test statistic\n");
    printf("----------------------------\n");
    test_statistic();

    //TEST ALGORITHM
    printf("----------------------------\n");
    printf("\t test algorithm\n");
    printf("----------------------------\n");
    test_algorithm();

    //TEST UTILITY
    printf("----------------------------\n");
    printf("\t test utility\n");
    printf("----------------------------\n");
    test_utility();

}
