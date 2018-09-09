#include <iostream>
#include <math.h>
#include <fstream>
#include <cassert>
using namespace std;

int n = 10;
double h = 0.1;
double x_0 = 0.0;
double y_0 = 1.0;


double k_1;
double k_2;
double k_3;
double k_4;


double f(double x, double y);
void RK4(double vx [], double vy []);


int main(int argc, char* argv[])
{   double vx [n+1];
    double vy [n+1];
    RK4(vx,vy);
}    


double f(double x, double y)
{
    return exp(x);
}


void RK4(double vx [], double vy [])
{   
    vx[0] = x_0;
    vy[0] = y_0;
    
    std::ofstream write_output("RK4.csv");
    assert(write_output.is_open());
    
    write_output << vx[0] << ',' << vy[0] << endl;
    
    for(int i = 1; i<=n; i++)
    {   k_1 = h * f(vx[i-1], vy[i-1]);
        k_2 = h * f(vx[i-1] + (h/2), vy[i-1] + (k_1/2));
        k_3 = h * f(vx[i-1] + (h/2), vy[i-1] + (k_2/2));
        k_4 = h * f(vx[i-1] + h, vy[i-1] + k_3);
        
        
        vy[i] = vy[i-1] + (1.0/6*(k_1 + 2*k_2 + 2*k_3 + k_4));
        vx[i] = vx[i-1] + h;
        
        write_output << vx[i] << ',' << vy[i] << endl; 
    }
    
    write_output.close();
}
