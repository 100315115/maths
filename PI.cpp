#include <iostream>
#include <math.h>

using namespace std;

double iterations = 9000000000;
double lower_limit = 0.0;
double upper_limit = 1.0;

double h = (upper_limit - lower_limit)/iterations;
double sum = 0.0;

int main(int argc, char* argv[])
{   
    for(double x = lower_limit + h; x<= upper_limit; x+= h)
    {
        sum += h * (4.0/(1 + pow((x),2)));
    }
    
    cout << sum << endl;
    return 0;
}