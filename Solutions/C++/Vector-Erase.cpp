#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n, x, a, b, c; 
    vector<int> vec;
    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        cin >> a;
        vec.push_back(a);
    }
    
    cin >> x >> b >> c;
    
    vec.erase(vec.begin() + x - 1);
    vec.erase(vec.begin() + b - 1, vec.begin() + c - 1);
    
    cout << vec.size() << endl;
    
    for(int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    
    return 0;
}
