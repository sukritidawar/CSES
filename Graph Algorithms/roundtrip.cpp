#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
int sv, ev; //Starting vertex of cycle and ending vertex of cycle
bool dfs(int s, int par, vector<bool> &vis, vector<int> &parent, vector<vector<int>> &g) {
    vis[s] = true;
    parent[s] = par;
    for(int u : g[s]) {
        if(!vis[u]) {
            if(dfs(u, s, vis, parent, g)) {
                return true;
            }
        }
        else {
            if(par != u) {
                sv = u;
                ev = s;
                return true;
            }
        }
    }
    return false;
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
    vector<bool> vis(v + 1, false);
    vector<int> parent(v + 1, -1);
    bool flag = true;
    for(int i = 1; i <= v; i++) {
        if(!vis[i]) {
            if(dfs(i, -1, vis, parent, g) == false) {
                flag = false;
            }
            else {
                ans.push_back(ev);
                int temp = ev;
                while(temp != sv) {
                    ans.push_back(parent[temp]);
                    temp = parent[temp];
                }
                ans.push_back(ev);
                cout << ans.size() << endl;
                for(int x : ans) {
                    cout << x << " ";
                }
                flag = true;
                break;
            }
        }
    }
    if(flag == false) {
        cout << "IMPOSSIBLE";
    }
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// vector<int> ans;
// int sv, ev; //Starting vertex of cycle and ending vertex of cycle
// bool dfs(int s, int par, vector<bool> &vis, vector<int> &parent, vector<vector<int>> &g) {
//     vis[s] = true;
//     parent[s] = par;
//     for(int u : g[s]) {
//         if(!vis[u]) {
//             if(dfs(u, s, vis, parent, g)) {
//                 return true;
//             }
//         }
//         else {
//             if(par != u) {
//                 sv = u;
//                 ev = s;
//                 return true;
//             }
//         }
//     }
//     return false;
// }

// int main() {
//     int v, e;
//     cin >> v >> e;
//     vector<vector<int>> g(v + 1);
//     for(int i = 0; i < e; i++) {
//         int u, x;
//         cin >> u >> x;
//         g[u].push_back(x);
//         g[x].push_back(u);
//     }
//     vector<bool> vis(v + 1, false);
//     vector<int> parent(v + 1);
//     int i;
//     bool flag = true;
//     for(i = 1; i <= v; i++) {
//         if(!vis[i]) {
//             bool x = dfs(i, -1, vis, parent, g);
//             if(x == false) {
//                 flag = false;
//                 cout << "IMPOSSIBLE";
//                 break;
//             }
//             else{
//                 flag = true;
//                 break;
//             }
//         }
//     }
//     if(flag == true) {
//         ans.push_back(ev);
//         int temp = ev;
//         while(temp != sv) {
//             ans.push_back(parent[temp]);
//             temp = parent[temp];
//         }
//         ans.push_back(ev);
//         cout << ans.size() << endl;
//         for(int x : ans) {
//             cout << x << " ";
//         }
//     } 
//     return 0;
// }
