#include <bits/stdc++.h>
using namespace std;

void process(vector<vector<char>> &g, int i, int j) {
    if(i < 0 || i >= g.size() || j < 0 || j >= g[0].size() || g[i][j] != '.') {
        return;
    }
    g[i][j] = '*';
    process(g, i - 1, j);
    process(g, i, j + 1);
    process(g, i + 1, j);
    process(g, i, j - 1);
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
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(g[i][j] == '.') {
                process(g, i, j);
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}
