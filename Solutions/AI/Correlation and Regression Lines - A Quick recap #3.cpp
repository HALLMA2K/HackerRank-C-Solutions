#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    double x[] = {15, 12, 8, 8, 7, 7, 7, 6, 5, 3}; // physics scores
    double y[] = {10, 25, 17, 11, 13, 17, 20, 13, 9, 15}; // history scores
    double n = 10; // number of students
    double sum_x = 0, sum_y = 0, sum_xy = 0, sum_x2 = 0;
    
    // calculate sum of x, y, xy, x^2
    for(int i = 0; i < n; i++) {
        sum_x += x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_x2 += pow(x[i], 2);
    }
    
    // calculate slope and intercept
    double slope = (n * sum_xy - sum_x * sum_y) / (n * sum_x2 - pow(sum_x, 2));
    double intercept = (sum_y - slope * sum_x) / n;
    
    // calculate probable score in history given a score of 10 in physics
    double physics_score = 10;
    double history_score = intercept + slope * physics_score;
    
    // print the result with one decimal place
    cout << fixed << setprecision(1) << history_score << endl;
    
    return 0;
}
