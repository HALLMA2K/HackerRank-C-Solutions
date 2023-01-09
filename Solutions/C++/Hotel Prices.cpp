#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class HotelRoom
{
    public:
        HotelRoom(int beds, int baths) : beds_(beds), baths_(baths) {}
        virtual int getPrice(){
          return 50 * beds_ + 100 * baths_;
        }

    private:
      int beds_;
      int baths_;
};

class HotelApartment : public HotelRoom
{
    public:
      HotelApartment(int beds, int baths) : HotelRoom(beds, baths){}
      int getPrice(){return HotelRoom::getPrice() + 100;}
    
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    vector<HotelRoom*> rooms;   
    string roomType;
    string standardRoom("standard");
    string apartmentRoom("apartment");
    int roomAmt, beds, baths;
    
    cin >> roomAmt;
    
    for(int i = 0; i < roomAmt; i++) {
        cin >> roomType;
        cin >> beds >> baths;
        if(roomType == standardRoom) {
            rooms.push_back(new HotelRoom(beds, baths));
        }
        else {
            rooms.push_back(new HotelApartment(beds, baths));
        }
    }
    int totalPrice = 0;
    
    for(auto room : rooms) {
        totalPrice += room->getPrice();
    }
    
    cout << totalPrice << endl;
    
    for(auto room : rooms) {
        delete room;
    }
    return 0;
}
