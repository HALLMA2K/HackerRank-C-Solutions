#include <cmath>
#include <cstdio>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;


double cdf(double x, double mu, double sigma) {
    return 0.5 + erf((x - mu) / (sigma * sqrt(2))) * 0.5;
}

int main() {
    const double mu = 50000;
    const double sigma = 10000;
    const int weeks = 11;
    const int start = 74000;
    const int weekly = 47000;
    const int end = start + weekly * weeks;
    const int lower_bound = end - 20000;
    
    const double sum_mu = weeks * mu;
    const double sum_sigma = sqrt(weeks) * sigma;
    const double probability = 1 - cdf(lower_bound, sum_mu, sum_sigma);
    
    cout <<  fixed << setprecision(4) << probability << endl;
    
    return 0;

}
