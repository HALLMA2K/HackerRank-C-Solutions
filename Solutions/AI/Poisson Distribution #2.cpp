#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    double mean_A = 0.88;
    double mean_B = 1.55;
    double cost_A = 160;
    double cost_B = 128;
    
    double expected_cost_A = cost_A + 40 * (mean_A + pow(mean_A, 2));
    double expected_cost_B = cost_B + 40 * (mean_B + pow(mean_B, 2));
    
    cout << fixed << setprecision(3) << expected_cost_A << endl;
    cout << fixed << setprecision(3) << expected_cost_B << endl;
    
    return 0;
}
