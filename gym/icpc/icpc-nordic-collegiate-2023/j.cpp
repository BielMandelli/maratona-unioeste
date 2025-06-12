#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

signed main()
{
    bieo;
    
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for(auto &x : a) cin >> x;

    sort(a.begin(), a.end(), greater<int>());

    int i = 0, j = n-1, gr = m-(n-m), ans = 0;
    if(gr >= n) ans = a[i];
    else {
        while(i < gr) {
            ans = max(ans, a[i]);
            i++;
        }
        while (i < j)
        {
            ans = max(ans, a[i]+a[j]);
            i++;j--;
        }
    }

    cout << ans << endl;

    return 0;
}