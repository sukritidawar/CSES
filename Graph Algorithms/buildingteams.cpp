#include <bits/stdc++.h>
using namespace std;

bool isBipartite(vector<vector<int>> &g, vector<int>& colors, int n, int node) {
    queue<int> q;
    q.push(node);
    colors[node] = 1;
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        int color = colors[curr];
        for(int u : g[curr]) {
            if(colors[u] == color) {
                return false;
            }
            if(colors[u] == -1) {
                colors[u] = 1 - color;
                q.push(u);
            }
        }
    }
    return true;
}

int main() {
    int v, e;
    cin >> v >> e;
    vector<vector<int>> g(v + 1);
    for(int i = 0; i < e; i++) {
        int u, x;
        cin >> u >> x;
        g[u].push_back(x);
        g[x].push_back(u);
    }
    vector<int> ans;
    vector<int> colors(v + 1, -1);
    int i;
    for(i = 1; i <= v; i++) {
        if(colors[i] == -1) {
            if(!isBipartite(g, colors, v, i)) {
                cout << "IMPOSSIBLE";
                break;
            }
        }
    }
    if(i == v + 1) {
        for(int j = 1; j <= v; j++) {
            ans.push_back(colors[j] + 1);
        }
        for(int j = 0; j < v; j++) {
            cout << ans[j] << " ";
        }
    }
    return 0;
}
