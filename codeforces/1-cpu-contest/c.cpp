#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main (){
    int t;
    cin >> t;
    while (t--)
    {
        int n, ans = 0;
        cin >> n;

        set<pair<int, int>> pSet;
        vector<pair<int, int>> p;
        vector<int> b(n+1);

        int x, y;
        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            p.emplace_back(x,y);
            pSet.insert(make_pair(x, y));
            b[x]++;
        }

        sort(p.begin(), p.end());

        for (int i = 0; i <= n; i++)
        {
            if (b[i] == 2) ans += n - 2;
        }

        for (int i = 0; i < n; i++)
        {
            x = p[i].first; y = p[i].second;
            if (pSet.count({x-1, y ^ 1}) &&
                pSet.count({x+1, y ^ 1}))
                {
                    ans++;
                } 
        }
        
        
        cout << ans << endl;
    }
    
    return 0;
}