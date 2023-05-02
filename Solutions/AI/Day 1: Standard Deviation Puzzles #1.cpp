#include <cmath>
#include <cstdio>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    double N1 = (3.0 - sqrt(2.0)) / 1.5;
    double N2 = (3.0 + sqrt(2.0)) / 1.5;
    
    cout << fixed << setprecision(2) << N2 << endl;
    
    return 0;
}
