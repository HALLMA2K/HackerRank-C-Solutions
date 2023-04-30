#include <cmath>
#include <cstdio>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    double y = 7; // given value of y
    double x = (9 * y + 107) / 20; // calculate x using line of x on y
    
    cout << fixed << setprecision(1) << x << endl;
    
    return 0;
}
