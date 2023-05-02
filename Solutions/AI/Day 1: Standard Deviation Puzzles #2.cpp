#include <cmath>
#include <cstdio>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    double mean = 0.675;
    double sd = 0.065;
    double height = 0.9025;
    
    double z = (height - mean) / sd;
    
    std::cout << std::fixed << std::setprecision(2) << z << std::endl;
    
    return 0;
}
