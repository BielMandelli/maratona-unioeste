#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

void solve(){
    int n,s;
    cin >> n >> s;

    int mx = -1, mn = 1e9;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mx = max(x, mx);
        mn = min(x, mn);
    }
    
    int op1 = abs(s - mn) + (mx - mn); 
    int op2 = abs(s - mx) + (mx - mn); 
    
    cout << min(op1, op2) << endl;
}

signed main()
{
    bieo;
    int t=1;
    cin >> t;

    while (t--) solve();
    
    return 0;
}