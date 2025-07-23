#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

void solve(){
    int n;
    cin >> n;
    vector<int> a(n), pos(n+1);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        pos[a[i]] = i;
    }
    
    int cnt = 1;
    for (int i = 0; i < n; i++)
    {
        if(a[i] != n){
            cnt += (pos[a[i]+1] < i);
        }
    }
    
    int k = 0;
    while(1 << k < cnt) k++;
    cout << k << endl;
}

signed main()
{
    bieo;
    int t=1;
    // cin >> t;

    while (t--) solve();
    
    return 0;
}