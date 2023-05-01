#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n = 100;            // number of students in line
    double mean = 2.4;      // mean number of tickets each student wants to buy
    double std_dev = 2.0;   // standard deviation of number of tickets each student wants to buy
    int tickets_left = 250; // number of tickets left
    
    double sample_mean = n * mean;    // mean of sample distribution
    double sample_std_dev = sqrt(n) * std_dev;   // standard deviation of sample distribution
    
    double z = (tickets_left - sample_mean) / sample_std_dev;   // calculate z-score
    
    double probability = 0.5 * (1 + erf(z / sqrt(2)));   // calculate probability using the error function
    
    cout << fixed << probability << endl;
    
    return 0;
}
