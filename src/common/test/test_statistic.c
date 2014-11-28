/*
 * fcl.beacon project
 *
 * FILE test_statistic.c
 * DATE 2013/08/27
 * AUTHOR Arden Zhao
 *
 * */

#include <stdio.h>
#include "../statistic/bc_statistic.h"
#include "../utility/bc_utility.h"
#include "../algorithm/bc_algorithm.h"


void test_statistic()
{
 
 // test sample data is generated from www.random.org 2013-11-13 08:13:41 UTC
 // number between 1 ~ 100. total 100 numbers.
 double d[]= { 24, 28, 4,  26, 53,
               73, 31, 27, 62, 77,
	       51, 82, 85, 52, 34,
	       76, 45, 66, 70, 51,
	       49, 99, 50, 47, 21,
	       33, 58, 3,  19, 96,
	       6,  64, 90, 35, 76,
	       75, 97, 39, 78, 59,
	       30, 45, 32, 58, 53,
	       99, 70, 63, 31, 53,
	       15, 53, 86, 67, 55,
	       87, 55, 89, 80, 94,
	       61, 96, 34, 65, 16,
	       81, 64, 4,  50, 4,
	       100,41, 66, 52, 62,
	       16, 77, 19, 24, 24,
	       49, 81, 50, 4,  22,
	       9,  54, 19, 38, 25,
	       72, 39, 45, 37, 42,
	       57, 88, 67, 35, 33};

 // sort sample data:
 double* sorted_data = ARRAY_CREATE(double, 100);
 ARRAY_COPY(sorted_data, d, 100);
 sort_double(sorted_data, 100);

 // MEAN
 double mean_value = mean(d,100);
 printf("function mean result: %f\n", mean_value);

 // COUNT
 size_t cnt = COUNT(d);
 printf("function count result: %d\n", cnt);

 // MIN
 double min_value = min(d, 100, 0);
 printf("function min without sorted result: %f\n", min_value);

 min_value = min(sorted_data, 100, 1);
 printf("function min with sorted result: %f\n", min_value);

 // MAX
 double max_value = max(d, 100, 0);
 printf("function max without sorted result: %f\n", max_value);

 max_value = max(sorted_data, 100, 1);
 printf("function max with sorted result: %f\n", max_value);

 // MEDIAN
 double median_value = median(d, 100, 0);
 printf("function median without sorted result: %f\n", median_value);

 median_value = median(sorted_data, 100, 1);
 printf("function median with sorted result: %f\n", median_value);

 // RANGE
 double range_value = range(d, 100, 0);
 printf("function range without sorted result: %f\n", range_value);

 range_value = range(sorted_data, 100, 1);
 printf("function range with sorted result: %f\n", range_value);

 //VARIANCE
 double variance_value = variance(d, 100);
 printf("function variance result: %f\n", variance_value);

 //VARIANCE_N1
 double variance_n1_value = variance_n1(d, 100);
 printf("function variance_n1 result: %f\n", variance_n1_value);

 //STDEV
 double stdev_value = stdev(d, 100);
 printf("function stdev result: %f\n", stdev_value);

 //STDEV_N1
 double stdev_n1_value = stdev_n1(d, 100);
 printf("function stdev_n1 result: %f\n", stdev_n1_value);

 //KURTOSIS
 double kurtosis_value = kurtosis(d, 100, mean_value, stdev_value);
 printf("function kurtosis result: %f\n", kurtosis_value);

 //EXCESS_KURTOSIS
 double excess_kurtosis_value = excess_kurtosis(d, 100, mean_value, stdev_value);
 printf("function excess_kurosis result: %f\n", excess_kurtosis_value);

 //SKEWNESS
 double skewness_value = skewness(d, 100, mean_value, stdev_value);
 printf("function skewness result: %f\n", skewness_value);




 // clean resource
 ARRAY_DELETE(sorted_data);

}
