#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define ll long long
#define endl '\n'

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x : a) cin >> x;

    vector<int> cnt(1e6+1);
    for (int i = 0; i < n; i++)
    {
        int x = a[i];
        int d = sqrt(x);
        for (int i = 1; i <= d; i++)
        {
            if(x%i == 0){
                cnt[i]++;
                if(i != x/i) cnt[x/i]++;
            }
        }
    }
    
    int ans = 1;
    for (int i = 1e6; i >= 1; i--)
    {
        if(cnt[i] >= 2) {
            cout << i << endl;
            break;
        }
    }

}

signed main()
{
    bieo;
    int t=1;
    // cin >> t;

    while (t--) solve();
    
    return 0;
}     