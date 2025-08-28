#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
// #define int long long
#define endl '\n'

void solve(){
    int n;
    cin >> n;

    int ans = 1;
    for (int i = 2; i*i <= n; i++)
    {
        int cur = 0;
        while (n%i == 0)
        {
            cur++;
            n /= i;
        }
        ans *= cur+1;
    }
    if(n>1) ans *=2;
    
    cout << ans << endl;
}

signed main()
{
    bieo;
    int t=1;
    cin >> t;

    while (t--) solve();
    
    return 0;
}