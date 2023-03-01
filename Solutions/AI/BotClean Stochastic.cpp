#include<iostream>
#include<vector>
using namespace std;
const int boardsize = 5;
class Location {
  public:
    int x,y;
};

void nextMove(int posr, int posc, vector<string> board) {

    Location b;
    b.x = posc;
    b.y = posr;
    Location d;
    string dirt = "d"; // initialize this to make string comp easier
    int i, j;
    
    for (i = 0; i < boardsize; i++) {

        for (j = 0; j < boardsize; j++) {

            if (dirt[0] == board[i][j]) {

                d.x = j; d.y = i;

                i = j = boardsize; // end the loop
            }
        }
    }
 
    bool didntClean = true;
    
    if ( (b.x == d.x) && (b.y == d.y) ) {
        
        cout << "CLEAN" << endl;
            
        didntClean = false; // avoid making two moves at once
    }

    if (didntClean) {
        // check the vertical first
        if (d.y < b.y) {

            cout << "UP" << endl;

        } else if (d.y > b.y) {

            cout << "DOWN" << endl;

        }
        else {
            if (d.x < b.x) {

                cout << "LEFT" << endl;

            }
            else if (d.x > b.x) {
                cout << "RIGHT" << endl;
            }
        }
    }
}

int main(void) {

    int pos[2];
    vector <string> board;
    
    cin>>pos[0]>>pos[1];
    
    for(int i=0;i<5;i++) {
        string s;
        cin >> s;
        board.push_back(s);
    }
    
    nextMove(pos[0], pos[1], board);
    
    return 0;
}
