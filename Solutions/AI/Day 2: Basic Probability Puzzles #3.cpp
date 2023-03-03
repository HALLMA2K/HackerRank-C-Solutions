#include <cstdio>
#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

int lcm(int a, int b) {
  int gcd = 1;
  
  for (int i = 2; i <= a && i <= b; ++i) {
    if (a % i == 0 && b % i == 0) {
      gcd = i;
    }
  }
  
  return (a * b) / gcd;
}

int main() {

    // Calculate the product of the fractions 4/7, 5/9, and 4/8
    int a_numerator = 4 * 5 * 4;
    int a_denominator = 7 * 9 * 8;
    int b_numerator = 4 * 4 * 4;
    int b_denominator = 7 * 9 * 8;
    int c_numerator = 3 * 5 * 4;
    int c_denominator = 7 * 9 * 8;
    
    // Simplify the result using the gcd (greatest common divisor) function from the <numeric> library
    int gcda = __gcd(a_numerator, a_denominator);
    a_numerator /= gcda;
    a_denominator /= gcda;
    int gcdb = __gcd(b_numerator, b_denominator);
    b_numerator /= gcdb;
    b_denominator /= gcdb;
    int gcdc = __gcd(c_numerator, c_denominator);
    c_numerator /= gcdc;
    c_denominator /= gcdc;
    
    // Find the LCM of the denominators
    int lcm1 = lcm(a_denominator, lcm(b_denominator, c_denominator));

    // Convert each fraction to an equivalent fraction with the LCM as the denominator
    a_numerator = a_numerator * (lcm1 / a_denominator);
    b_numerator = b_numerator * (lcm1 / b_denominator);
    c_numerator = c_numerator * (lcm1 / c_denominator);

    // Calculate the sum of the fractions
    int result_numerator = a_numerator + b_numerator + c_numerator;
    int result_denominator = lcm1;

    // Simplify the result using the gcd (greatest common divisor) function from the <numeric> library
    int gcd = __gcd(result_numerator, result_denominator);
    result_numerator /= gcd;
    result_denominator /= gcd;
    
    std::cout << result_numerator << "/" << result_denominator << std::endl;

    return 0;
}
