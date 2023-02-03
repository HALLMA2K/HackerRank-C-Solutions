#include <iostream>
#include <vector>
using namespace std;


void nextMove(int n, int r, int c, vector <string> grid) {
    
    // Bot pos
    int bX = c;
    int mY = r;
  
    // Princess pos
    int pX, pY;
    string pC = "p";
    
    // Loop through the grid to find the position of the princess
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(pC[0] == grid[i][j]) {
                pX = j;
                pY = i;
                i = j = n; // end the loops once princess is found
            }
        }
    }
    
    // Check if the princess is above or below the bot
    if(pY < bY) {
        cout << "UP" << endl;
    }
    else if(pY > bY) {
        cout << "DOWN" << endl;
    }
    else {
        // Check if the princess is to the left or right of the bot
        if(pX < bX) {
            cout << "LEFT" << endl;
        }
        else if(pX > bX) {
            cout << "RIGHT" << endl;
        }
    }   
}

int main(void) {

    int n, r, c;
    vector <string> grid;

    cin >> n;
    cin >> r;
    cin >> c;

    for(int i=0; i<n; i++) {
        string s; cin >> s;
        grid.push_back(s);
    }

    nextMove(n, r, c, grid);
    return 0;
}
