#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

int calc(int x){
    int sum = 0;
    while(x > 0){
        sum += (x%10);
        x /= 10; 
    }
    return sum;
}

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> cnt(1e6+1);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }

    int ans = 0;
    for (int i = 1e6; i >= 0; i--)
    {
        k -= cnt[i];
        // cout << k << "<-k i-> " << i << endl;
        if(k<=0) {
            ans = calc(i);
            break;
        }
        if(i-calc(i)>=0) cnt[i-calc(i)] += cnt[i];
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