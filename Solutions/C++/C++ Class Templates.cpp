#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

/* Startup code to speed up */
__attribute__((constructor))
void static speed_up() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}
/*Write the class AddElements here*/
template <class T>
class AddElements {
    public:
        AddElements (T arg) {element=arg;}
        T add (T x) {return x+element;}
    private:
        T element;
};

// class template specialization:
template <>
class AddElements <string> {
    public:
        AddElements (string arg) {element=arg;}
        string concatenate (string arg) {
            string s = element+arg;
            return s;
        }
    private:
        string element;
};

int main () {
  int n, i;
  cin >> n;
  
  for(i = 0; i < n; i++) {
    string type;
    cin >> type;
    if(type == "float") {
        double element1,element2;
        cin >> element1 >> element2;
        
        AddElements<double> myfloat (element1);
        cout << myfloat.add(element2) << endl;
    }
    else if(type == "int") {
        int element1, element2;
        cin >> element1 >> element2;
        
        AddElements<int> myint (element1);
        cout << myint.add(element2) << endl;
    }
    else if(type == "string") {
        string element1, element2;
        cin >> element1 >> element2;
        
        AddElements<string> mystring (element1);
        cout << mystring.concatenate(element2) << endl;
    }
  }
  return 0;
}
