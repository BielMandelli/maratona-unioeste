#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
 
signed main()
{
    bieo;
    int n,m,x,y;
    cin >> n >> m >> x >> y;
    vector<int> s(n), b(m);
    for(auto &x : s) cin >> x;
    for(auto &x : b) cin >> x;

    sort(s.begin(), s.end());
    sort(b.begin(), b.end());

    vector<pair<int,int>> ans;
    int l = 0, r = 0;
    while (r < m && l < n)
    {
        if(s[l]-x <= b[r] && b[r] <= s[l]+y) {
            ans.push_back({l+1, r+1});
            l++;
            r++;
        } else if(s[l] < b[r]) l++;
        else r++;

        // cout << "r: " << b[r] << " l:" << s[l] << endl;
    }

    cout << ans.size() << endl;
    for(auto x : ans) cout << x.first << " " << x.second << endl;
    
}