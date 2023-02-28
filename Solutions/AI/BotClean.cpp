#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

const int boardsize = 5;
class Location {
  public:
    int x,y;
};

void next_move(int posr, int posc, vector <string> board) {
    //add logic here

    Location b;
    b.x = posc; b.y = posr;

    vector<Location> dirtSpots;
    string dirt = "d";

    int i, j;
    for (i = 0; i < boardsize; i++) {
        for (j = 0; j < boardsize; j++) {
            if (dirt[0] == board[i][j]) {
                Location d;
                d.x = j; d.y = i;
                dirtSpots.push_back(d);
            }
        }
    }
    if( dirtSpots.empty() ) return;

    Location d = dirtSpots.front();
    int minManhattan = INT_MAX;
    for(auto spot: dirtSpots){
        int manhattanDistance = abs(b.x - spot.x) + abs(b.y - spot.y);
        if(manhattanDistance < minManhattan){
            minManhattan = manhattanDistance;
            d = spot;
        }
    }
    
    bool didntClean = true;
    
    if ( (b.x == d.x) && (b.y == d.y) ) {
        cout << "CLEAN" << endl;
        dirtSpots.erase(dirtSpots.begin());
        didntClean = false;
        
    }

    int manhattanDistanceX = abs(b.x - d.x);
    int manhattanDistanceY = abs(b.y - d.y);
    if(didntClean)
    {
        if (manhattanDistanceX > manhattanDistanceY) {
            if (b.x > d.x) {
                cout << "LEFT" << endl;
            } else {
                cout << "RIGHT" << endl;
            }
        } else {
            if (b.y > d.y) {
                cout << "UP" << endl;
            } else {
                cout << "DOWN" << endl;
            }
        }
    }
}


int main(void) {
    int pos[2];
    vector <string> board;
    cin>>pos[0]>>pos[1];
    for(int i=0;i<5;i++) {
        string s;cin >> s;
        board.push_back(s);
    }
    next_move(pos[0], pos[1], board);
    return 0;
}
