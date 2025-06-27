#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

void solve(){
    int k;
    string s;
    cin >> s >> k;

    vector<vector<char>> c(k);
    for (int i = 0; i < s.size(); i++) c[i%k].push_back(s[i]);
    
    for (int i = 0; i < k; i++) sort(c[i].begin(), c[i].end(), greater<char>());
    for (int i = 0; i < s.size(); i++) {
        if(c[i%k].empty()) continue;
        cout << c[i%k].back();
        c[i%k].pop_back();
    }
    cout << endl;
}

signed main()
{
    bieo;
    int t=1;
    // cin >> t;

    while (t--) solve();
    
    return 0;
}