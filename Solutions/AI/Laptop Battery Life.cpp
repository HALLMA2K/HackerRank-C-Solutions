#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(), find_if(s.begin(), s.end(),
        not1(ptr_fun<int, int>(isspace)))
    );
    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(find_if(s.rbegin(), s.rend(), not1(ptr_fun<int,
    int>(isspace))).base(),s.end());

    return s;
}

int main()
{
    string timeCharged_temp;
    getline(cin, timeCharged_temp);

    float f;
    stringstream ss(timeCharged_temp);
    ss >> f;
    f *= 2.0;
    if (f > 8) {
        cout << "8.00" << endl;
    
    }
    else {
        cout << f << endl;
    }
    return 0;
}
