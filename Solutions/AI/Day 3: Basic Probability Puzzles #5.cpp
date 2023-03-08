#include <iostream>

void ConvertToLowestTerms(int& firstNum, int& secondNum) {

    int Low_Value, High_Value;

    if (firstNum > secondNum) {
        Low_Value = secondNum;
        High_Value = firstNum;
    } else {
        High_Value = secondNum;
        Low_Value = firstNum;
    }

    for (int i = Low_Value; i > 0; i--) {
        if ((Low_Value % i == 0) && (High_Value % i == 0)) {
            firstNum = firstNum / i;
            secondNum = secondNum / i;

            break;
        }
    }
}

int factorial(int n) {
    return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

int main() {
    int people = 10;

    int top = 2 * factorial(people - 2);
    int bottom = factorial(people - 1);

    ConvertToLowestTerms(top, bottom);

    std::cout << top << "/" << bottom << std::endl;

    return 0;
}
