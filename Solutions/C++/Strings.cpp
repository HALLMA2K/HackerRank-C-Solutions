#include <iostream>
#include <string>
using namespace std;

int main() {
	  // Complete the program
    string str1, str2;
    cin >> str1 >> str2;
    
    cout << str1.length() << " " << str2.length() << endl;
    
    string str3 = str1 + str2;
    cout << str3 << endl;
    
    char temp1, temp2;
    temp1 = str1[0];
    temp2 = str2[0];
    str2[0] = temp1;
    str1[0] = temp2;
    cout << str1 << " " << str2 << endl;
    
    return 0;
}
