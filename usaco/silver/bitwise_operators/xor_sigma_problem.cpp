#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

void solve(){
    int n;
    cin >> n;

    int cur = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        cur ^= x;
    }
    
    cout << cur << endl;
}

signed main()
{
    bieo;
    int t=1;
    // cin >> t;

    while (t--) solve();
    
    return 0;
}