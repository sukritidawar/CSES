#include <bits/stdc++.h>
using namespace std;

void dfs(int s, vector<bool> &vis, vector<vector<int>> &g) {
    vis[s] = true;
    for(int u : g[s]) {
        if(!vis[u]) {
            dfs(u, vis, g);
        }
    }
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
    int cc = 0;
    // cout << v << e;
    vector<bool> vis(v + 1, false);
    vector<int> lead;
    for(int i = 1; i <= v; i++) {
        if(!vis[i]) {
            cc++;
            lead.push_back(i);
            dfs(i, vis, g);
        }
    }
    cout << cc - 1 << endl;
    if(cc > 1) {
        int u = lead[0];
        for(int i = 1; i < lead.size(); i++) {
            int x = lead[i];
            cout << u << " " << x << endl;
            u = x;
        } 
    }
    return 0;
}
