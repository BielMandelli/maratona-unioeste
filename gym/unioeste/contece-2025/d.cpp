#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

void solve() {
    string s;
    cin >> s;

    vector<int> cnt(26);
    int mx = 0, cur = 1;
    for (int i = 1; i < s.size(); i++) {
        if(s[i] == s[i-1]) cur++;
        else {
            mx = max(mx, cur);
            cur = 1;
        }
    }
     mx = max(mx, cur);
    cout << mx << endl;
}


signed main()
{
    bieo;
    int t=1;
    // cin >> t;

    while (t--) solve();
    
    return 0;
}