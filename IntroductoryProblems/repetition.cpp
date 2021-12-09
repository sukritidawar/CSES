#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> dp(n, 0);
    dp[0] = 1;
    int ans = 1;
    for(int i = 1; i < n; i++) {
        if(s[i - 1] == s[i]) {
            dp[i] = max(dp[i - 1] + 1, dp[i]);
        }
        else {
            dp[i] = 1;
        }
        ans = max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}