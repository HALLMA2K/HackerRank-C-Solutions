#include <iomanip>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to compute the Pearson product-moment correlation coefficient
double pearson_correlation_coefficient(const vector<int>& x, const vector<int>& y) {
    // Compute the means of x and y
    double x_mean = 0, y_mean = 0;
    for (int i = 0; i < x.size(); i++) {
        x_mean += x[i];
        y_mean += y[i];
    }
    x_mean /= x.size();
    y_mean /= y.size();

    // Compute the standard deviations of x and y
    double x_std_dev = 0, y_std_dev = 0;
    for (int i = 0; i < x.size(); i++) {
        x_std_dev += pow(x[i] - x_mean, 2);
        y_std_dev += pow(y[i] - y_mean, 2);
    }
    x_std_dev = sqrt(x_std_dev / x.size());
    y_std_dev = sqrt(y_std_dev / y.size());

    // Compute the covariance of x and y
    double covariance = 0;
    for (int i = 0; i < x.size(); i++) {
        covariance += (x[i] - x_mean) * (y[i] - y_mean);
    }
    covariance /= x.size();

    // Compute the Pearson product-moment correlation coefficient
    double correlation_coefficient = covariance / (x_std_dev * y_std_dev);

    return correlation_coefficient;
}

int main() {
    int n;
    
    cin >> n;

    // Read in the scores of N students in Mathematics, Physics, and Chemistry
    vector<int> math_scores(n), physics_scores(n), chemistry_scores(n);
    for (int i = 0; i < n; i++) {
        cin >> math_scores[i] >> physics_scores[i] >> chemistry_scores[i];
    }

    // Compute the Pearson product-moment correlation coefficient for each pair of subjects
    double math_physics_correlation = pearson_correlation_coefficient(math_scores, physics_scores);
    double physics_chemistry_correlation = pearson_correlation_coefficient(physics_scores, chemistry_scores);
    double math_chemistry_correlation = pearson_correlation_coefficient(math_scores, chemistry_scores);
    
    cout << fixed << setprecision(2) << math_physics_correlation << endl;
    cout << fixed << setprecision(2) << physics_chemistry_correlation << endl;
    cout << fixed << setprecision(2) << math_chemistry_correlation << endl;

    return 0;
}
