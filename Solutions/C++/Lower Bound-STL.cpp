#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int needle, n;
    vector<int> haystack;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        int tempVals;
        cin >> tempVals;
        haystack.push_back(tempVals);
    }
    
    int q;
    cin >> q;
    
    for(int i = 0; i < q; i++) {
        int temp;
        cin >> temp;
        
        vector<int>::iterator iter;
        iter = lower_bound(haystack.begin(), haystack.end(), temp);
        
        if(*(iter + 1) == temp || *iter == temp) {
            cout << "Yes " << iter - haystack.begin() + 1 << endl;
        }
        else {
        cout << "No " << iter - haystack.begin() + 1 << endl;
        }
    }
    return 0;
}
