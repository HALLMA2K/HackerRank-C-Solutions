#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    vector<int> NewVect;
    int size, values;
    cin >> size;
    
    for(int i = 0; i < size; i++)
    {
        cin >> values;
        NewVect.push_back(values);
    }
  
    sort(NewVect.begin(), NewVect.end());
  
    for(int i = 0; i < size; i++)
    {
        cout << NewVect[i] << " ";
    }
  
    return 0;
}
