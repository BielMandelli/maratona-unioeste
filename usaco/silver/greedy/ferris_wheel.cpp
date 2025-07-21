#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

void solve(){
    int n,x; 
    cin >> n >> x;
    vector<int> a(n);
    for(auto &x : a) cin >> x;

    sort(a.begin(), a.end());

    int ans = 0;
    int i = 0, j = n-1;
    vector<bool> ch(n+1);
    while (i < j)
    {
        if(a[i]+a[j] <= x){
            ans++;
            ch[i] = true;
            ch[j] = true;
            i++;
            j--;
        } else j--;
    }
    
    for(auto x : ch) if(!x) ans++; 
    
    cout << ans-1 << endl;
}

signed main()
{
    bieo;
    int t=1;
    // cin >> t;

    while (t--) solve();
    
    return 0;
}