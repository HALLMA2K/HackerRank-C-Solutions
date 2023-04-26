#include <cmath>
#include <cstdio>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n = 10;
    int physics[] = {15, 12, 8, 8, 7, 7, 7, 6, 5, 3};
    int history[] = {10, 25, 17, 11, 13, 17, 20, 13, 9, 15};

    // Calculate the mean of physics scores
    double sumPhysics = 0;
    for (int i = 0; i < n; i++) {
        sumPhysics += physics[i];
    }
    double meanPhysics = sumPhysics / n;

    // Calculate the mean of history scores
    double sumHistory = 0;
    for (int i = 0; i < n; i++) {
        sumHistory += history[i];
    }
    double meanHistory = sumHistory / n;

    // Calculate the numerator of the Pearson correlation coefficient formula
    double numerator = 0;
    for (int i = 0; i < n; i++) {
        numerator += (physics[i] - meanPhysics) * (history[i] - meanHistory);
    }

    // Calculate the denominator of the Pearson correlation coefficient formula
    double denominator1 = 0;
    for (int i = 0; i < n; i++) {
        denominator1 += pow(physics[i] - meanPhysics, 2);
    }
    double denominator2 = 0;
    for (int i = 0; i < n; i++) {
        denominator2 += pow(history[i] - meanHistory, 2);
    }
    double denominator = sqrt(denominator1 * denominator2);

    // Calculate the Pearson correlation coefficient
    double r = numerator / denominator;

    // Output the result
    cout << fixed << setprecision(3) << r << endl;

    return 0;
}
