#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

signed main() {
    bieo;
    
    ll t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> p(n);

        int n0 = 0;
        for(auto &x : p) {
            cin >> x;
            if(!x) n0++;
        }

        int valid = true;
        for (int i = 0; i < n-1; i++)
        {
            if(p[i] == 0 && ((i-1 >= 0 && p[i-1] == 0) or p[i+1] == 0)) valid = false;
        }
        
        if(!n0) valid = false;
        
        if(!valid) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
    return 0;
}