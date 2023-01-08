#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int number, queries;
    cin >> number >> queries;
    vector<vector<int>> vect(number);
    
    // loop through index
    for(int i = 0; i < number; i++)
    {
        int length;
        cin >> length;
        vect[i].resize(length);
        
        for(int j = 0; j < length; j++)
        {
            cin >> vect[i][j];
        }
    }
    
    for(int k = 0; k < queries; k++)
    {
        int i, j;
        cin >> i >> j;
        
        cout << vect[i][j] << "\n";
    }
    
    return 0;
}
