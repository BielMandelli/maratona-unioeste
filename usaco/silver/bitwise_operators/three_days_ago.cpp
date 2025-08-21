#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

void solve(){
    string s;
    cin >> s;

    map<int, int> freq;
    int mask = 0;
    freq[0] = 1; 
    int ans = 0;
    for(auto c : s){
        int d = c - '0';
        mask ^= (1 << d);

        ans += freq[mask];

        freq[mask]++;
    }
    
    cout << ans << endl;
}

signed main()
{
    bieo;
    int t=1;
    // cin >> t;

    while (t--) solve();
    
    return 0;
}