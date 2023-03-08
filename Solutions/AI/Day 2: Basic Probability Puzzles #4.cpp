#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> continued_fraction(double num) {

    vector<int> result;
    int whole = floor(num);
    
    result.push_back(whole);
    
    double fraction = num - whole;

    while (abs(fraction) > 0.0001) {
        int inverse = floor(1.0 / fraction);
        result.push_back(inverse);
        fraction = 1.0 / fraction - inverse;
    }

    return result;
}

int main() {

    int bag1_red = 4, bag1_black = 5;
    int bag2_red = 3, bag2_black = 7;

    double bag1_total = bag1_red + bag1_black;
    double bag2_total = bag2_red + bag2_black;

    double probability1 = (bag1_red / bag1_total) * (bag2_black / bag2_total) * ((bag2_black - 1.0) / (bag2_total - 1.0));
    double probability2 = (bag1_black / bag1_total) * (bag2_black / bag2_total) * (bag2_red / (bag2_total - 1.0));
    double probability3 = (bag1_black / bag1_total) * (bag2_red / bag2_total) * (bag2_black / (bag2_total - 1.0));
    double totalProbability = probability1 + probability2 + probability3;
   
    vector<int> fractions = continued_fraction(totalProbability);

    int n = fractions.size();
    int numerator = fractions[n - 1];
    int denominator = 1;

    for (int i = n - 2; i >= 0; i--) {
        int tmp = numerator;
        numerator = fractions[i] * numerator + denominator;
        denominator = tmp;
    }

    cout << numerator << "/" << denominator << endl;

    return 0;
}
