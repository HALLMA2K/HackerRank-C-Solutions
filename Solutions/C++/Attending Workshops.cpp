#include<bits/stdc++.h>

using namespace std;

//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops
struct Workshops {
    int workshop_start;
    int workshop_end;
    int workshop_duration;
    
    bool operator<(const Workshops & rhs) {
        return this->workshop_end < rhs.workshop_end;
    }     
};


ostream &operator<<(ostream &os, const Workshops &obj) {
    os << obj.workshop_start << ": " << obj.workshop_end <<
    ": " << obj.workshop_duration << endl;
    return os;
}


struct Available_Workshops {
    int n;
    vector<Workshops> vec;
};

Available_Workshops *initialize(int start_time[], int duration[], int num) {
  Available_Workshops *Avail =  new Available_Workshops;
  
  Avail->n = num;
  Workshops test;
  
  for(int i = 0; i < num; i++) {
      test.workshop_start =start_time[i];
      test.workshop_duration = duration[i];
      test.workshop_end = start_time[i] + duration[i];
      Avail->vec.push_back(test);
  }  
  
  sort(Avail->vec.begin(), Avail->vec.end());
  return Avail;
}

int CalculateMaxWorkshops(Available_Workshops *test) {
    int w_count = 1;
    int test_end_time = test->vec.at(0).workshop_end;

    for(int i{1}; i < test->n; i++) {
        if(test_end_time <= test->vec.at(i).workshop_start) {
            w_count++;
            test_end_time = test->vec.at(i).workshop_end;
        }
    }
    return w_count;   
}


int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i = 0; i < n; i++) {
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    
    return 0;
}
