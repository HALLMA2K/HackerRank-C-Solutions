#include <iostream>
#include <vector>
#include <numeric>
#include <iomanip>

using namespace std;

int main() {
    vector<int> physicsScores = {15, 12, 8, 8, 7, 7, 7, 6, 5, 3};
    vector<int> historyScores = {10, 25, 17, 11, 13, 17, 20, 13, 9, 15};

    int n = physicsScores.size();
    double sumX = accumulate(physicsScores.begin(), physicsScores.end(), 0.0);
    double sumY = accumulate(historyScores.begin(), historyScores.end(), 0.0);
    double sumXY = 0, sumX2 = 0;

    for (int i = 0; i < n; i++) {
        sumXY += physicsScores[i] * historyScores[i];
        sumX2 += physicsScores[i] * physicsScores[i];
    }

    double slope = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);

    cout << fixed << setprecision(3) << slope << endl;

    return 0;
}
