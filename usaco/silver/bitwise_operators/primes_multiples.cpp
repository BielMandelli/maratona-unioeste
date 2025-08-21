#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

void solve(){
    int n, k;
    cin >> n >> k;

    int ans = 0;
    vector<int> p(k);
    for (int i = 0; i < k; i++){
        cin >> p[i];
    }
    
    for (int i = 1; i < (1 << k); i++)
    {
        int cur = 1;
        for (int j = 0; j < k; j++)
        {
            if(i & (1 << j)){
                if(cur > n/p[j]){
                    cur = n+1;
                    break;
                }
                cur *= p[j];
            }
        }

        if(__builtin_popcount(i)%2) ans += n/cur;
        else ans -= n/cur;
    }
    
    cout << ans << endl;
}

signed main()
{
    bieo;
    int t=1;
    // cin >> t;

    while (t--) solve();
    
    return 0;
}