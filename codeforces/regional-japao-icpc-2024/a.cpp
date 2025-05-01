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
        vector<int>a(n);

        for(auto &x : a) cin >> x;

        int init = 300, ans = 0;
        for (int i = 0; i < n; i++)
        {
            if(a[i] <= init){
                ans+= a[i];
                init -= a[i];
            }
        }
        cout << ans << endl;
    }
    return 0;
}