#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

int main() {
    unordered_set<long> s;
    long n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        s.insert(i);
    }
    vector<long> arr(n);
    for(int i = 0; i < n-1; i++) {
        int x;
        cin >> x;
        arr[i] = x;
    }
    for(int i = 0; i < n; i++) {
        s.erase(arr[i]);
    }
    cout << *(s.begin());
    return 0;
}