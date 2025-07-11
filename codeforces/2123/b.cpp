#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

void solve(){
    int n,j,k;
    cin >> n >> j >> k;
    vector<int> a(n);

    int w;
    bool gr = false;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(i+1 == j) w = a[i];
    }

    for (int i = 0; i < n; i++) if(i+1 != j && a[i] > w) gr = true;
    
    bool valid = true;
    if(k == 1 && gr) valid = false;
    
    cout << ((valid) ? "YES" : "NO") << endl;
}

signed main()
{
    bieo;
    int t=1;
    cin >> t;

    while (t--) solve();
    
    return 0;
}