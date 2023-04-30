#include <cmath>
#include <cstdio>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    double slope2 = 20.0/9.0;
    double slope1 = 5.0/4.0;
    double result = (slope2/slope1)*(pow(3, 2));
    
    cout << fixed << setprecision(1) << result << endl;
    
    return 0;
}
