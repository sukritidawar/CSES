#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

typedef long long ll;

void solve() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    ll ans = 0;
    for(int i = 1; i < n; i++) {
        ans += (arr[i] < arr[i - 1]) ? (arr[i - 1] - arr[i]) : 0;
        arr[i] += (arr[i] < arr[i - 1]) ? (arr[i - 1] - arr[i]) : 0;
    }
    cout << ans << endl;
}

int main() {
    #ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    #endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
    return 0;
}