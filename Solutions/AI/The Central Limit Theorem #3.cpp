#include <cmath>
#include <cstdio>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    double mu = 500; // population mean
    double sigma = 80; // population standard deviation
    int n = 100; // sample size
    double lower = 490; // lower bound of the interval
    double upper = 510; // upper bound of the interval

    // calculate the z-scores
    double lower_z = (lower - mu) / (sigma / sqrt(n));
    double upper_z = (upper - mu) / (sigma / sqrt(n));

    // find the probability of z being between lower_z and upper_z
    double probability = (0.5 * (erf(upper_z / sqrt(2)) - erf(lower_z / sqrt(2))));
    
    cout << setprecision(4) << fixed << probability << endl;

    return 0;
}
