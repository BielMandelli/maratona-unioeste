#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

void solve() {
    int n;
    string s;
    cin >> n >> s;

    map<int, int> freq;
    freq[0] = 1; 

    int mask = 0;
    int ans = 0;

    for (auto c : s) {
        int bit = c - 'a'; 
        mask ^= (1 << bit);

        ans += freq[mask]; 
        for (int i = 0; i < 8; i++) ans += freq[mask ^ (1 << i)]; 

        freq[mask]++;
    }

    cout << ans << endl;
}

signed main() {
    bieo;
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}