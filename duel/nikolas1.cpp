#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
#define int long long
const int MOD = 1e9+7;

signed main(){
    fastio;

    int n;
    cin >> n;

    int cur = 0, up = 1;
    while (cur < n)
    {
        cur+=up;
        up++;
    }

    int ans;
    if(cur == n) ans = up-1;
    else ans = abs(cur - n - (up -1));
    
    cout << ans << endl;  
}