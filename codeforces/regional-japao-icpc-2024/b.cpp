#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

signed main() {
    bieo;
    while(1){
       int n;
       cin >> n;
       if(!n) break;
       vector<int> a(n), b(n);

       for(auto &x : a) cin >> x;
       for(auto &x : b) cin >> x;

       int lead = 0, p1 = 0, p2 = 0, ans = 0;
       for (int i = 0; i < n; i++)
       {    
            int cur;

            p1 += a[i];
            p2 += b[i];

            if(p1 > p2) cur = 1;
            else if (p1 < p2) cur = 2;
            else cur = lead;
            
            if(lead && cur != lead) ans++;
            
            lead = cur;
       }
       
       cout << ans << endl;
    }

    return 0;
}