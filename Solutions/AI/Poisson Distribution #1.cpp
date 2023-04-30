#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    double mean = 2.5;
    int k = 5;
    
    double probability = exp(-mean) * pow(mean, k) / tgamma(k+1);
    
    cout << fixed << setprecision(3) << probability << endl;
    
    return 0;
}
