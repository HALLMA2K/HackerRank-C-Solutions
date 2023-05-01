#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n = 49;             // number of boxes
    double mean = 205;      // mean box weight
    double std_dev = 15;    // standard deviation of box weight
    double max_weight = 9800;   // maximum weight elevator can transport
    
    double sample_mean = n * mean;  // mean of sample distribution
    double sample_std_dev = sqrt(n) * std_dev;   // standard deviation of sample distribution
    
    double z = (max_weight - sample_mean) / sample_std_dev;   // calculate z-score
    
    double probability = 0.5 * (1 + erf(z / sqrt(2)));   // calculate probability using the error function
    
    cout << fixed << probability << endl;
    
    return 0;
}
