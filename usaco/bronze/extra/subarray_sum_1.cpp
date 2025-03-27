#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long

signed main()
{
    bieo;
    int n, x,  ans = 0;
    cin >> n >> x;
    vector<int> a(n);
    for(auto &xs : a) {
        cin >> xs;
        if(x == xs) ans++;
    }

    int l = 0, r = 0, sum = 0;
    while(l <= r && l != n-1){
        if(sum < x && r < n){
            sum += a[r];
            r++;
        } 
        
        if(sum >= x){
            if(sum == x) ans++;
            sum -= a[l];
            l++;
        }

        // cout << "l " << l << " r " << r << " sum "  << sum << endl;
    }
    
    cout << ans << endl;
    
    return 0;
}