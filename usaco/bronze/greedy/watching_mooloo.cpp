#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
#define int long long
const int MOD = 1e9 + 7;

signed main()
{
    fastio;
    int n, k;
    cin >> n >> k;
    vector<int> day(n);
    for(auto &x : day) cin >> x;

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if(i == 0) ans += 1+k;
        else {
            int cont = day[i] - day[i-1];
            int newc = 1+k;
            ans += min(newc, cont);
        }
    }
    
    cout << ans << endl;
    
    return 0;
}