#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

constexpr int MAXN = 105;

int n;
double gpa[MAXN], score[5][MAXN];

double calc_correlation(int x) {
    double sum_x = 0, sum_y = 0, sum_xy = 0, sum_xx = 0, sum_yy = 0;
    
    for (int i = 0; i < n; i++) {
        double xi = score[x][i];
        double yi = gpa[i];
        sum_x += xi;
        sum_y += yi;
        sum_xy += xi * yi;
        sum_xx += xi * xi;
        sum_yy += yi * yi;
    }
    
    double cov = sum_xy / n - sum_x / n * sum_y / n;
    double std_dev_x = sqrt(sum_xx / n - sum_x / n * sum_x / n);
    double std_dev_y = sqrt(sum_yy / n - sum_y / n * sum_y / n);
    double correlation = cov / std_dev_x / std_dev_y;
    
    return correlation;
}

int main() {
    int T;
    
    cin >> T;
    
    while (T--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> gpa[i];
        }
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < n; j++) {
                cin >> score[i][j];
            }
        }
        
        double max_corr = -1;
        int best_test = -1;
        
        for (int i = 0; i < 5; i++) {
            double corr = calc_correlation(i);
            if (abs(corr) > max_corr) {
                max_corr = abs(corr);
                best_test = i;
            }
        }
        
        cout << best_test + 1 << endl;
    }
    
    return 0;
}
