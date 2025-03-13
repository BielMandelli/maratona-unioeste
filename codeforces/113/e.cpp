#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
#define int long long
const int MOD = 1e9+7;

signed main(){
    fastio;

    int n;
    cin >> n;

    int ans = 1, p1 = 0, p2 = 0, aux = 0;
    for (int i = 0; i < n; i++)
    {
        p1 = (2*aux + ans)%MOD;
        p2 = (3*aux)%MOD;
        aux = p1;
        ans = p2;
    }
    
    cout << ans << endl;

    return 0;
} 