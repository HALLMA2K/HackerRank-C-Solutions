#include <cmath>
#include <cstdio>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>

using namespace std;

double fact(int n) {
    return n == 0 ? 1 : n*fact(n-1);
}

double poi(int k, double lam) {
    return pow(lam,k)*exp(-lam)/fact(k);
}

int main() {
    // Probability that the number of errors on page 10 is 2
    double lambda = 1.2;
    int k = 2;
    double P_X_2 = exp(-lambda) * pow(lambda, k) / tgamma(k+1);
    
    cout << setprecision(3) << fixed << P_X_2 << endl;

    // Probability that the number of errors on page 1 is less than 3
    k = 0;
    double P_X_lt_3 = 0;
    for (int i = 0; i < 3; i++) {
        P_X_lt_3 += exp(-lambda) * pow(lambda, i) / tgamma(i+1);
    }
    
    cout << setprecision(3) << fixed << P_X_lt_3 << endl;

    // Probability that the number of errors on first ten pages totals 5
     //3
    k = 5;
    int lam = 12;
    
    cout << setprecision(3) << std::fixed << poi(k, lam) << std::endl;

    // Probability that the number of errors on all forty pages adds up to at least 3
    lambda = 1.2 * 40;
    k = 2;
    double P_S_ge_3 = 1 - exp(-lambda) * (pow(lambda, 0) / tgamma(0+1) +
      pow(lambda, 1) / tgamma(1+1) + pow(lambda, 2) / tgamma(2+1));
    
    cout << setprecision(3) << fixed << P_S_ge_3 << endl;

    return 0;
}
