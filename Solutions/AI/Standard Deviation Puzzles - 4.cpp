#include <cmath>
#include <cstdio>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    double meanX = 10.0;
    double sdX = 3.0;
    double meanY = 20.0;
    double sdY = 4.0;
    
    double sdZ = std::sqrt(std::pow(sdX, 2) + std::pow(sdY, 2));
    
    std::cout << std::fixed << std::setprecision(1) << sdZ << std::endl;
    
    return 0;
}
