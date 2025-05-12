#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

signed main() {
    bieo;
    int n;
    cin >> n;
    vector<pair<int,int>> c(n);
    for (int i = 0; i < n; i++)
    {
        int x,y;
        cin >> c[i].second >> c[i].first;
    }
    
    sort(c.begin(), c.end());
    int l = 0, r = n-1, ans = 0;
    while (l <= r)
    {
        ans = max(ans, c[l].first + c[r].first);
        if(c[l].second-1 == 0) l++;
        else c[l].second--;

        if(c[r].second-1 == 0) r--;
        else c[r].second--;
    }
    
    cout << ans << endl;
    
    return 0;
}
