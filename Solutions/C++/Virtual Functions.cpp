#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

static int studentID = 0;
static int professorID = 0;

class Person
{
    public:
    string name;
    int age;
    
    virtual void getdata(){ cin >> name; cin >> age;}
    virtual void putdata(){cout << name << " " << age << " ";}
   
    private:
};

class Professor : public Person
{
    public:
      int publication;
      int cur_id;
      
      Professor(){professorID++;}
      void getdata(){Person::getdata(); cin >> publication;      this->cur_id = professorID;}
      void putdata(){Person::putdata(); cout << publication << " " << cur_id << endl;}
      
    private:
};

class Student : public Person
{
    public:
      int marks[6];
      int cur_id;
      
      Student(){studentID++;}
      void getdata(){Person::getdata(); for(int i = 0; i < 6;i++){cin >> marks[i];} cur_id = studentID; }
      void putdata(){Person::putdata(); cout << this->sum() << " " << cur_id << endl;}
      int sum(){int sum = 0; for(int i = 0; i < 6; i++){sum += marks[i];} return sum;}
      
    private:
};

int main(){

    int n, val;
    cin >> n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin >> val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i = 0; i < n; i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;
}
