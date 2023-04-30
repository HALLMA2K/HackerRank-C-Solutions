#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

int main() {
    // Probability that no calls come in a given 1 minute period
    double lambda = 3;
    int k = 0;
    
    double P_X_0 = exp(-lambda) * pow(lambda, k) / tgamma(k+1);
    
    cout << fixed << setprecision(3) << P_X_0 << endl;

    // Probability that atleast 2 calls will arrive in a given 2 minute period
    lambda = 6;
    double P_Y_lt_2 = 0;
    
    for (int i = 0; i < 2; i++) {
        P_Y_lt_2 += exp(-lambda) * pow(lambda, i) / tgamma(i+1);
    }
    
    double P_Y_ge_2 = 1 - P_Y_lt_2;
    
    cout << fixed << setprecision(3) << P_Y_ge_2 << endl;

    return 0;
}
