#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

int solve(){
    int n, h;
    cin >> n >> h;
    vector<int> a(n);
    for(auto &x : a) cin >> x;

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if(a[i] <= h) ans++;
    }
    
    return ans;
}

signed main()
{
    bieo;
    int t=1;
    // cin >> t;

    while (t--) cout << solve() << endl;
    
    return 0;
}