#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
#define int long long
const int MOD = 1e9 + 7;

signed main()
{
    fastio;
    int n;
    cin >> n;
    vector<pair<int,int>> c(n);
    for (auto &x : c) cin >> x.first >> x.second;
    sort(c.begin(), c.end());

    int ans = 0, last = c[0].first;
    for (int i = 0; i < n; i++)
    {
        if(last < c[i].first) last = c[i].first + c[i].second;
        else last += c[i].second;
    }

    cout << last << endl;
    
    return 0;
}