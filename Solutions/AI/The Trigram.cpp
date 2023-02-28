#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <limits.h>

using namespace std;

string to_lower(string str) {
    string lower = str;
    for (int i=0; i<str.size(); i++) {
        lower[i] = (lower[i]>='A' && lower[i]<='Z')?(lower[i]-'A'+'a'):(lower[i]);
    }
    return lower;
}

int main() {
    string s1="", s2="", s3="";
    string inS = "";
    string maxTrigram = "";
    int maxCount = INT_MIN;
    unordered_map<string, int> triCounts;
    while(!cin.eof()) {
        cin >> inS;
        inS = to_lower(inS);
        if (s1 == "") {
            s1 = inS;  
        } 
        else if (s2 == "") {
            s2 = inS;
        }
        else{
            if (s3 != "") {
                s1 = s2;
                s2 = s3;
            }
            
            s3 = inS;
            
            string trigram = s1 + " " + s2 + " " + s3;
            if (triCounts.find(trigram) == triCounts.end()) {
                triCounts[trigram] = 0;
            }
            
            triCounts[trigram] += 1;
            if (triCounts[trigram] > maxCount) {
                maxCount = triCounts[trigram];
                maxTrigram = trigram;
            }
        }     
    }
    cout << maxTrigram << "\n";
    return 0;
}
