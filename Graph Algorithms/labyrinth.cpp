#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> moves = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}}; //L, R, U, D

bool isValid(int x, int y, vector<vector<char>> &g, vector<vector<bool>> &vis) {
    if(x < 0 || x >= g.size() || y < 0 || y >= g[0].size() || vis[x][y] == true) {
        return false;
    }
    return true;
}

void bfs(vector<vector<char>> &g, vector<vector<bool>> &vis, vector<vector<pair<int, int>>> &parents, int sx, int sy, int ex, int ey) {
    queue<pair<int, int>> q;
    q.push({sx, sy});
    while(!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        for(pair<int, int> mv : moves) {
            int mvx = mv.first, mvy = mv.second;
            if(isValid(cx + mvx, cy + mvy, g, vis)) {
                q.push({cx + mvx, cy + mvy});
                vis[cx + mvx][cy + mvy] = true;
                parents[cx + mvx][cy + mvy] = {mvx, mvy};
            }
        }
    }
} 

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> g(n, vector<char>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }
    vector<vector<bool>> vis(n, vector<bool>(m,false));
    vector<vector<pair<int, int>>> parents(n, vector<pair<int, int>>(m, {-1,-1}));
    int sx, sy, ex, ey;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(g[i][j] == '#') {
                vis[i][j] = true;
            }
            if(g[i][j] == 'A') {
                sx = i;
                sy = j;
            }
            else if(g[i][j] == 'B') {
                ex = i;
                ey = j;
            }
        }
    }
    bfs(g, vis, parents, sx, sy, ex, ey);
    if(!vis[ex][ey]) {
        cout << "NO";
        return 0;
    }
    cout << "YES" << endl;
    vector<pair<int, int>> ans;
    pair<int, int> end = {ex, ey};
    while(end.first != sx or end.second != sy) {
        ans.push_back(parents[end.first][end.second]);
        end.first -= ans.back().first;
        end.second -= ans.back().second;
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(auto c : ans) {
        int x = c.first, y = c.second;
        // cout << x << " " << y << " " << endl;
        if(x == 0 && y == 1) {
            cout << "R";
        }
        else if(x == 1 && y == 0) {
            cout << "D";
        }
        else if(x == -1 && y == 0) {
            cout << "U";
        }
        else if(x == 0 && y == -1) {
            cout << "L";
        }
    }
    return 0;
}
