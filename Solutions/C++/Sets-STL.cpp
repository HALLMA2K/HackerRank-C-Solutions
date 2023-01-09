#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    set<int> intSet;
    int setCount;
    cin >> setCount;
    
    for(int i = 0; i < setCount; i++) {
        int x, y;
        cin >> x >> y;
        
        switch(x)
        {
            case 1:
                intSet.insert(y);
                break;
            case 2:
                intSet.erase(y);
                break;
            case 3:
                cout << (intSet.find(y) == intSet.end() ? "No" : "Yes") << endl;
                break;
        }
    }   
    return 0;
}
