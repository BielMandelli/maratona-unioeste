#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long

signed main()
{
    bieo;
    int n;
    cin >> n;
    vector<int> c(n);
    for(auto &x : c) cin >> x;

    int even = 0, odd = 0;
    for (int i = 0; i < n; i++)
    {
        if(!(c[i]%2)) even++;
        else odd++;
    }

    int ans = 0, last = 1;
    while(odd > even) odd-=2, even++;
    if(even>odd) even = odd + 1;
    ans = odd + even;
    
    cout << ans << endl;

    return 0;
}