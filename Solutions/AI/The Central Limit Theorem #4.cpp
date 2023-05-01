#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    double mean = 500; // population mean
    double sd = 80; // population standard deviation
    int n = 100; // sample size
    double alpha = 0.05; // significance level
    double z_alpha = 1.96; // z-score for alpha/2

    double se = sd / sqrt(n); // standard error of the mean
    double margin_error = z_alpha * se; // margin of error
    double lower = mean - margin_error; // lower bound of confidence interval
    double upper = mean + margin_error; // upper bound of confidence interval

    cout  << lower << endl << upper << endl;

    return 0;
}
