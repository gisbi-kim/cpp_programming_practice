#include <iostream>
#include <string>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <array>

//long long bino(long long n, long long r);

class binoDP
{

private:
    static const int max_num = 100;
    std::array< std::array<long long, max_num>, max_num> cache;
   
public:
    binoDP()
    {
        // cache initialization
        for(auto & row : cache) 
            for(auto & col : row) 
                col = -1;
    }
   
    long long bino_fast(long long n, long long r)
    {
        // initial case 
        if( r==0 || n==r ) 
            return 1;
            
        if( cache[n][r] != -1 )
            return cache[n][r];
            
        return cache[n][r] = bino_fast(n-1, r-1) + bino_fast(n-1, r);
    }
    
    long long bino_slow(long long n, long long r)
    {
        // initial case 
        if( r==0 || n==r ) 
            return 1;
                        
        return bino_slow(n-1, r-1) + bino_slow(n-1, r);
    }

};


int main(int argc, char** argv)
{
    std::cout << std::string{"Start"} << std::endl;
    std::cout << std::endl;

    // take argvs 
    int n = std::atoi(argv[1]);
    int r = std::atoi(argv[2]);     
    
    
    // time counter: fast 
    std::clock_t start_fast = std::clock();
    binoDP bino_calculator; 
    long long val_fast = bino_calculator.bino_fast(n, r); // main 
    double duration_fast = ( std::clock() - start_fast ) / (double) CLOCKS_PER_SEC;

    // time counter: slow 
    std::clock_t start_slow = std::clock();
    long long val_slow = bino_calculator.bino_slow(n, r); // main 
    double duration_slow = ( std::clock() - start_slow ) / (double) CLOCKS_PER_SEC;


    // log print 
    std::cout<< "Fast Operation took: "<< duration_fast <<" seconds." << std::endl;
    std::cout<< "Fast result of (" << n << ", " << r << ") is " << val_fast << std::endl;       
    std::cout << std::endl;

    std::cout<< "Slow Operation took: "<< duration_slow <<" seconds." << std::endl;
    std::cout<< "Slow result of (" << n << ", " << r << ") is " << val_slow << std::endl;       
    std::cout << std::endl;

    return 0;
}



