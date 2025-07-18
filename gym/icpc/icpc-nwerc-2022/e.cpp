#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

void solve()
{
    int a,b;
    char c;
    cin >> a >> c >> b;
    
    int n, x, mn, mx;
    bool can = false;
    for (n = b; n < 1e6+1; n+=b)
    {

        x = a*n/b;
        mn = n-1;
        mx = (n*(n-1))/2;

        if(mn <= x && x <= mx) {
            can = true;
            break;
        }
    }

    if(!can){
        cout << "impossible" << endl;
        return;
    }

    vector<int> d(n), p(n);
    for (int i = mn; i > 0; i--)
    {
        if(mx > x){
            int diff = min(mx - x, i -1);

            mx -= diff;
            d[i] = i - diff;
        }
        else {
            d[i] = i;
            p[i] = i;
        }
    }
    
    cout << n << " " << mn << endl;
    for (int i = 1; i < n; i++) cout << i+1 << " " << p[d[i]-1]+1 << endl;
}

signed main()
{
    bieo;
    int t = 1;
    // cin >> t;

    while (t--) solve();

    return 0;
}