#include <bits/stdc++.h>

using namespace std;

pair<int, int> pacPos, foodPos;
int n, m;

int dr[] = {-1, 0, 0, 1};
int dc[] = {0, -1, 1, 0};

char** grid;

vector<pair<int, int>> path;

bool inbounds(pair<int, int> pos) {
    return 0 <= pos.first && pos.first < n && 0 <= pos.second && pos.second < m;
}

int main() {
    cin >> pacPos.first >> pacPos.second >> foodPos.first >> foodPos.second >> n >> m;
    grid = new char*[n];
    for(int i = 0; i < n; i++) {
        grid[i] = new char[m];
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    // Begin UCS
    priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > fringe;
    fringe.push(make_pair(0, make_pair(pacPos.first, pacPos.second)));
    
    int dist[n][m];
    memset(dist, -1, sizeof dist);
    dist[pacPos.first][pacPos.second] = 0;

    int pred[n][m];
    pred[pacPos.first][pacPos.second] = -1;

    while (!fringe.empty()) {
        pair<int, pair<int, int> > state = fringe.top(); fringe.pop();
        pair<int, int> pos = state.second;
        if (state.first > dist[pos.first][pos.second]) continue;
        if (pos.first == foodPos.first && pos.second == foodPos.second) {
            break;
        }
        for(int d = 0; d < 4; d++) {
            pair<int, int> next = make_pair(pos.first + dr[d], pos.second + dc[d]);
            int priority = state.first + 1;
            if (inbounds(next) && 
                (dist[next.first][next.second] > priority || dist[next.first][next.second] == -1) &&
                grid[next.first][next.second] != '%') {
                pred[next.first][next.second] = d;
                dist[next.first][next.second] = priority;
                fringe.push(make_pair(priority, next));
            }
        }
    }

    pair<int, int> current = make_pair(foodPos.first, foodPos.second);
    while (pred[current.first][current.second] != -1) {
        path.push_back(current);
        int d = pred[current.first][current.second];
        pair<int, int> next = make_pair(current.first - dr[d], current.second - dc[d]);
        current = next;
    }
    path.push_back(current);
    reverse(path.begin(), path.end());

    // End DFS

    cout << path.size() - 1 << endl;
    for(int i = 0; i < path.size(); i++) {
        pair<int, int> pos = path[i];
        cout << pos.first << " " << pos.second << endl;
    }
    
    return 0;
}
