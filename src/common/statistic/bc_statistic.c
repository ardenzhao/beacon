/*
 * fcl.beacon project
 *
 * FILE bc_statistic.c
 * DATE 2013/08/27
 * AUTOHR Arden Zhao
 *
 * */

#include <assert.h>
#include <math.h>
#include "bc_statistic.h"
#include "../utility/bc_utility.h"
#include "../algorithm/bc_algorithm.h"

double mean( const double data[], const size_t size)
{
    long double mean = 0;
    size_t i;

    for( i = 0; i < size ; i++ )
    {
        mean += data[i]/size;
    }

    return mean;
}

double min(const double data[], const size_t size, const int b_sorted)
{
	double min = data[0];
	size_t i = 0;

	assert(size > 0);
	if(b_sorted)
	{
		return data[0];
	}
	else
	{
		for(i=1; i<size; i++)
		{
			min = min > data[i] ? data[i]: min;
		}
		return min;
	}
}

double max(const double data[], const size_t size, const int b_sorted)
{
	double max = data[0];
	size_t i=0;

	assert(size > 0);
	if(b_sorted)
	{
		return data[size-1];
	}
	else
	{
		for(i=1; i<size; i++)
		{
			max = max < data[i] ? data[i]: max;
		}
		return max;
	}
}

double median(const double data[], const size_t size, const int b_sorted)
{
  double median;
  const size_t lhs = (size - 1) / 2;
  const size_t rhs = size / 2;
  
  if (size == 0)
    return 0.0 ;

  if(!b_sorted) // create copy of array and then sort it.
  {
      double* sorted_data = ARRAY_CREATE(double,size);
      assert(sorted_data);
      ARRAY_COPY(sorted_data, data, size);
      
      sort_double(sorted_data, size);
      
      median = (lhs == rhs)? sorted_data[lhs]: (sorted_data[lhs] + sorted_data[rhs])/2.0;
      ARRAY_DELETE(sorted_data); 
  }
  else	
  {
      median = (lhs == rhs)? data[lhs]: (data[lhs] + data[rhs])/2.0;
  }

  return median ;	
}

double range(const double data[], const size_t size, const int b_sorted)
{
    double min_value = data[0];
    double max_value = data[0];
    int i;
    if(b_sorted)
    {
        return max(data,size,b_sorted) - min(data,size,b_sorted);
    }
    else
    {
        for(i = 1; i < size; i++)
        {
            min_value = min_value > data[i]? data[i] : min_value;
            max_value = max_value < data[i]? data[i] : max_value;
        }
        return max_value - min_value;
    }
}

// variance equals to "mean of square minus square of mean"
double variance(const double data[], const size_t size)
{
    if(size < 2 )
       return 0.0;
    int i;
    long double sx = 0.0;
    long double sxx = 0.0;
    for(i = 0; i< size; i ++)
    {
        sx += data[i];
        sxx += data[i]*data[i];
    }
    
    double var = sxx/size - (sx/size)*(sx/size);
    if( var > 0)
        return var;
    
    return 0.0;
}

double variance_n1(const double data[], const size_t size)
{
     if(size < 2 )
        return 0.0;
     int i;
     long double sx = 0.0;
     long double sxx = 0.0;
     for(i = 0; i< size; i ++)
     {
         sx += data[i];
         sxx += data[i]*data[i];
     }

     double var = (sxx - sx*sx/size)/(size -1);
     if( var > 0)
         return var;

     return 0.0;
}

double stdev(const double data[], const size_t size)
{
    return sqrt( variance(data, size) );
}

double stdev_n1(const double data[], const size_t size)
{
    return sqrt( variance_n1(data, size) );
}

double kurtosis(const double data[], const size_t size, const double mean, const double stdev)
{
    long double avg =0;
    int i;
    for( i = 0; i < size; i++)
    {
        const long double x = (data[i] - mean) / stdev;
        avg += (x*x*x*x - avg)/(i+1);
    }
    return avg;      
}


double excess_kurtosis(const double data[], const size_t size, const double mean, const double stdev)
{
    return kurtosis(data, size, mean, stdev) - 3.0;
}

double skewness(const double data[], const size_t size, const double mean, const double stdev)
{
    long double skew = 0;
    int i;
    for( i = 0; i < size; i++)
    {
        const long double x = (data[i] - mean)/ stdev;
        skew += (x*x*x - skew)/(i + 1);
    }
    return skew;
}


double q1(const double data[], const size_t size, const int b_sorted)
{
    return quantile( data, size, b_sorted, 0.25);
}

double q3(const double data[], const size_t size, const int b_sorted)
{
    return quantile (data, size, b_sorted, 0.75);
}

// median absolute deviation
double mad(const double data[], const size_t size, const int b_sorted)
{
    double med = median(data, size, b_sorted);
    double* new_array = ARRAY_CREATE(double, size);
    double result;    
    int i;
    for( i = 0; i < size; i++)
    {
        new_array[i] = abs(data[i] - med);
    }
    result = median(new_array, size, 0);
    ARRAY_DELETE(new_array);
    return result;
}

double average_deviation(const double data[], const size_t size, const int b_sorted)
{
    double sum = 0.0;
    double m = 0.0;
    int i;

    m = median(data, size, b_sorted);
    for ( i = 0; i < size; i++)
    {
        sum += abs(data[i] - m);
    }
    
    return sum/size;
}

double cp(const double data[], const size_t size, const double speclow, const double spechigh)
{
    double stdev_value = stdev(data, size);
    return (spechigh - speclow)/(6.0 * stdev_value);
}

double cpk(const double data[], const size_t size, const double speclow, const double spechigh)
{
    double stdev_value = stdev(data, size);
    double mean_value  = mean(data, size);
    double cp_upper = (spechigh - mean_value)/(3.0 * stdev_value);
    double cp_lower = (mean_value - speclow)/(3.0 * stdev_value);
    
    return cp_upper < cp_lower ? cp_upper : cp_lower;
}

double iqr(const double data[], const size_t size, const int b_sorted)
{
    return q1(data, size, b_sorted) - q3(data, size, b_sorted);
}


double iqm(const double data[], const size_t size, const int b_sorted)
{
    double q1_value = q1(data, size, b_sorted);
    double q3_value = q3(data, size, b_sorted);
    long double sum = 0;
    int count = 0;
    int i;
    for( i = 0; i < size; i++)
    {
        if( data[i] >= q1_value && data[i] <= q3_value)
        {
            sum += data[i];
            count++;
        } 
    }
    if (count == 0)
      return 0.0; // hope that will never happen..
    return sum/count;
}


double quantile(const double data[], const size_t size, const int b_sorted, const double f)
{
    const double index = f * (size - 1);
    const size_t lhs = (int)index;
	const double delta = index - lhs;
	double result;

    assert( f >= 0.0 && f <= 1.0 );
   
     
    if(b_sorted)
    {
        if (size == 0) 
            return 0.0;
        if ( lhs == size - 1)
            return data[lhs];
        else
            return (1 - delta) * data[lhs] + delta * data[lhs + 1];
    }
    else
    {
        double* sorted_data = ARRAY_CREATE(double,size);
        assert(sorted_data);
        ARRAY_COPY(sorted_data, data, size);
      
        sort_double(sorted_data, size);
        
        if( size == 0)
            result =  0.0;
        if( lhs == size -1)
            result = sorted_data[lhs];
        else
            result = (1 - delta) * sorted_data[lhs] + delta * sorted_data[lhs + 1];
        
        ARRAY_DELETE(sorted_data); 
    }
    
    return result;
}


