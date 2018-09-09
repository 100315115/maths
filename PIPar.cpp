#include <omp.h>
#include <iostream>
#include <math.h>

using namespace std;

// I AM DOING THIS FOR 4 THREADS (do export bla bla bla  to change the numner of threads)

int n_threads = 4;

double iterations = 9000000000;
double lower_limit = 0.0;
double upper_limit = 1.0;

double h = (upper_limit - lower_limit)/iterations;

main(int argc, char* argv[])
{   
    double sums[n_threads];
    
    #pragma omp parallel 
    {
        int t_num = omp_get_thread_num();
        
        double t_sum = 0.0;
        
        for(double x = lower_limit + ((t_num + 1)*h); x <= upper_limit; x += h * n_threads)
        {
            t_sum += h * (4.0/(1 + pow((x),2)));
        }
    	
    	sums[t_num] = t_sum;	

    }
    
    double result;
    
    for(int i = 0; i<n_threads; i++)
        result += sums[i];
    
    cout << result << endl;
    
}