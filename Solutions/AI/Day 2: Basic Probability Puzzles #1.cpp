#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_SIDES 36

int helper()
{
    int sum = 0;
    int count = 0;
    int total = MAX_SIDES;
  
    for (int i = 1; i < 7; i++) {
        for (int j = 1; j < 7; j++) {
            if (i + j > 9)
            {
                count++;
            }
        }
    }

    //reduce fraction
    int temp = 0;
  
    temp = __gcd(count, MAX_SIDES);
    total = total / temp;
    count = count / temp;
  
    cout << total - count << "/" << total << endl;
  
    return 0;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    helper();
  
    return 0;
}
