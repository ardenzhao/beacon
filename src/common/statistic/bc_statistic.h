/*
 * fcl.beacon project
 *
 * FILE bc_statistic.h
 * DATE 2013/08/27
 * AUTHOR Arden Zhao
 *
 * */
#ifndef __BC_STATISTIC_H__
#define __BC_STATISTIC_H__

#include <stdlib.h>

#define COUNT(x) (sizeof(x) / sizeof(x[0]))

double mean( const double data[], const size_t size);

double min(const double data[], const size_t size, const int b_sorted);

double max(const double data[], const size_t size, const int b_sorted);

double median(const double data[], const size_t size, const int b_sorted);

double range(const double data[], const size_t size, const int b_sorted);

double variance(const double data[], const size_t size);

double variance_n1(const double data[], const size_t size);

double stdev(const double data[], const size_t size);

double stdev_n1(const double data[], const size_t size);

double kurtosis(const double data[], const size_t size, const double mean, const double stdev);

double excess_kurtosis(const double data[], const size_t size, const double mean, const double stdev);

double skewness(const double data[], const size_t size, const double mean, const double stdev);

double q1(const double data[], const size_t size, const int b_sorted);

double q3(const double data[], const size_t size, const int b_sorted);

double mad(const double data[], const size_t size, const int b_sorted);

double average_deviation(const double data[], const size_t size, const int b_sorted);

double cp(const double data[], const size_t size, const double speclow, const double spechigh);

double cpk(const double data[], const size_t size, const double speclow, const double spechigh);

double iqr(const double data[], const size_t size, const int b_sorted);

double iqm(const double data[], const size_t size, const int b_sorted);

double quantile(const double data[], const size_t size, const int b_sorted, const double f);

#endif /*__BC_STATISTIC_H__ */

