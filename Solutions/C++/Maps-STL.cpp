#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    map<string,int> m;
    int numQueries = 0;
    cin >> numQueries;
    
    for(int i = 0; i < numQueries; i++) {
        int queriesType = 0, marks = 0;
        string name;
        cin >>queriesType;
        
        switch(queriesType)
        {
            case 1:
                cin >> name;
                cin >> marks;
                m[name] += marks;
                break;
            case 2:
                cin >>name;
                m.erase(name);
                break;
            case 3:
                cin >> name;
                map<string, int>::iterator iter = m.find(name);
                if(iter != m.end()) {
                    cout << m[name] << endl;
                }
                else {
                    cout << 0 << endl;
                } 
        }
    }
    return 0;
}
