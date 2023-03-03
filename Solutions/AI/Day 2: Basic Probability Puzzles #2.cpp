#include <iostream>
#include <cmath>

using namespace std;

class Fraction {
private:
    int num;
    int den;

public:
    Fraction(int n, int d) {
        num = n;
        den = d;
    }

    int get_num() {
        return num;
    }

    int get_den() {
        return den;
    }
};

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

Fraction to_fraction(double decimal) {
    int numerator = 1;
    int denominator = 1;
    double error = 1.0;
    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= 1000; j++) {
            double diff = abs(decimal - (double)i / (double)j);
            if (diff < error) {
                error = diff;
                numerator = i;
                denominator = j;
            }
        }
    }
    int common_divisor = gcd(numerator, denominator);
    numerator /= common_divisor;
    denominator /= common_divisor;
    return Fraction(numerator, denominator);
}

int main() {
    float probability = 1.0 / 6.0;
    int values = 6;
    float result = 0.0;

    // First dice
    for (int i = 1; i <= values; i++) {
        // Second dice
        for (int j = 1; j <= values; j++) {
            // Verify if each die will be different and their sum is 6
            if (i != j && (i + j) == 6) {
                result += pow(probability, 2);
            }
        }
    }
    Fraction fraction = to_fraction(result);

    // Final probability found
    cout << fraction.get_num() << "/" << fraction.get_den() << endl;

    return 0;
}
