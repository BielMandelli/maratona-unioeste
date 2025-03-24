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

    vector<pair<string, string>> c;
    string s, s2;
    for (int i = 0; i < n; i++)
    {
        cin >> s >> s2;
        c.emplace_back(s.substr(0,2), s2);
    }

    map<string, int> seen;
    int ans = 0;
    for (auto v : c){
        if (v.first != v.second) ans += seen[v.second + v.first];
        seen[v.first + v.second]++;
    }
    
    cout << ans << endl;
    
    return 0;
}