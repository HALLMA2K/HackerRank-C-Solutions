#include <iostream>
#include <vector>
using namespace std;

void displayPathtoPrincess(int n, vector <string> grid){
    //your logic here
    int times = n/2;
    string vertical, horizontal;
    
    // set defaults to ignore unecessary evals/assignments
    vertical = "UP"; horizontal = "RIGHT";
    
    string p = "p";
    // figure out which corner the princess is in
    if (p[0] == grid[0][0]) {
        horizontal = "LEFT";
    } else if (p[0] == grid[n-1][0]) {
        vertical = "DOWN";
        horizontal = "LEFT";
    } else if (p[0] == grid[n-1][n-1]) {
        vertical = "DOWN";
    }

    int i = 0;
    for (i = 0; i < times; i++)
        cout << vertical << endl;
    for (i = 0; i < times; i++)
        cout << horizontal << endl;
}

int main(void) {

    int m;
    vector <string> grid;

    cin >> m;

    for(int i=0; i<m; i++) {
        string s; cin >> s;
        grid.push_back(s);
    }

    displayPathtoPrincess(m,grid);

    return 0;
}
