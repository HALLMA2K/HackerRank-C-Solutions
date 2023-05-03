#include <iostream>
#include <vector>
#include<stack>
#include<utility>

using namespace std;

vector< pair<int,int> > visited;//visited points so as to store them for printing.
stack< pair<int,int> > DFS;
char visit[30][30];//to keep a record of the visited vertices.

//w is white,b is black and g is grey
void dfs(int x, int y, int pacman_x, int pacman_y, int food_x, int food_y, vector <string> grid) {
    pair<int,int> v;
    DFS.push(make_pair(pacman_x,pacman_y));
    
    while(DFS.empty()==false) {
        v=DFS.top();
        if(v.first==food_x&&v.second==food_y) { 
            visit[v.first][v.second]='g';
            visited.push_back(v);
            return;
        }
       if(visit[v.first][v.second]=='g') {
           visit[v.first][v.second]='b';
           DFS.pop();
           continue;
       }
       if(visit[v.first][v.second]=='b') {
           DFS.pop();
           continue;
       }  
      visit[v.first][v.second]='g';
      visited.push_back(v);
      //now check for neighbours
      if(grid[v.first-1][v.second]!='%'&&v.first>=1&&visit[v.first-1][v.second]=='w') {
          DFS.push(make_pair(v.first-1,v.second));
      }
      if(grid[v.first][v.second-1]!='%'&&v.second>=1&&visit[v.first][v.second-1]=='w') {
         DFS.push(make_pair(v.first,v.second-1));
      }
      if(grid[v.first][v.second+1]!='%'&&v.second+1<=y-1&&visit[v.first][v.second+1]=='w') {
         DFS.push(make_pair(v.first,v.second+1));
      }
      if(grid[v.first+1][v.second]!='%'&&v.first+1<=x-1&&visit[v.first+1][v.second]=='w') {
         DFS.push(make_pair(v.first+1,v.second));
      }
   }
}

int main(void) {

    int x,y, pacman_x, pacman_y, food_x, food_y;
    
    cin >> pacman_x >> pacman_y;//pacman coordinates
    cin >> food_x >> food_y;//food coordinates
    cin >> x >> y;//rows and columns
    
    vector <string> grid;//grid is a vector of strings

    for(int i=0; i<x; i++) {
        string s; cin >> s;//input row by row
        grid.push_back(s);
    }
    for(int i=0;i<x;i++) {
        for(int j=0;j<y;j++) {
            visit[i][j]='w';//vertices not visited
        }
    }
    
    dfs( x, y, pacman_x, pacman_y, food_x, food_y, grid);//perform dfs starting from pacman_x,pacman_y
    
    int count=0;//number of vertices explored during dfs are all visited nodes
    count=visited.size(); 
    cout<<count<<endl;
    
    for(int i=0;i<visited.size();i++) {  
        cout<<visited[i].first<<" "<<visited[i].second<<endl;
    }
    
    int d=0;
    vector< pair<int,int> >path;
    
    for(int i=0;i<visited.size();i++) {
        if(visit[visited[i].first][visited[i].second]=='g') {
            d++;
            path.push_back(visited[i]);
        }
    }
    
    d--;
    cout<<d<<endl;
    
    for(int i=0;i<path.size();i++) {
            cout<<path[i].first<<" "<<path[i].second<<endl;
    }
    
    return 0;
}
