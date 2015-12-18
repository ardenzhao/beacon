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
extern void test_logging(int priority);

int main(int argc, char** argv )
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

    //TEST LOGGING
    printf("----------------------------\n");
    printf("\t test logging\n");
    printf("----------------------------\n");
    int priority = 10;    
    if(argc > 1)
    {
        if( strcmp( argv[1], "log_level_trace") == 0)
        {
            priority = 1;
        }
        else if(strcmp ( argv[1], "log_level_debug") == 0)
        {
            priority = 2;
        }
        else if( strcmp(argv[1], "log_level_info") == 0)
        {
            priority = 3;
        }
        else if (strcmp(argv[1], "log_level_warning") == 0)
        {
            priority = 5;
        }
        else if ( strcmp (argv[1], "log_level_error") ==0 )
        {
            priority = 6;
        }
    }

    test_logging(priority);


}
