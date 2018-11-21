#include <iostream>
#include <string>
#include <chrono>
#include <cstdlib>
#include <ctime>

long long bino(long long n, long long r);

int main(int argc, char** argv)
{
    std::cout << std::string{"Start"} << std::endl;

    // take argvs 
    int n = std::atoi(argv[1]);
    int r = std::atoi(argv[2]);     
    
    // time counter: start 
    std::clock_t start = std::clock(); // get current time

    // main 
    long long val = bino(static_cast<long long>(n), static_cast<long long>(r));

    // time counter: end
    double duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

    std::cout<< "The result of (" << n << ", " << r << ") is " << val << std::endl;       
    std::cout<< "Operation took: "<< duration <<" seconds." << std::endl;

    return 0;
}


long long bino(long long n, long long r)
{
    // initial case 
    if( r==0 || n==r ) 
        return 1;
        
    return bino(n-1, r-1) + bino(n-1, r);
}
