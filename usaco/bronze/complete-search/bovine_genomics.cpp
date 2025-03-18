#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
#define int long long
const int MOD = 1e9 + 7;

signed main()
{
    fastio;

    int n, m;
    cin >> n >> m;

    set<char> pc[m], sc[m];
    vector<string> ps;
    char c;
    for (int i = 0; i < n; i++)
    {
        string s;
        for (int j = 0; j < m; j++)
        {
            cin >> c;
            s += c;
            sc[j].insert(c);
        }
    }

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        ps.push_back(s);
    }

    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        bool valid = true;
        for (int j = 0; j < n; j++)
        {
            if(sc[i].count(ps[j][i]) > 0) {
                    valid = false;
                    break;
            }
        }
        if(valid) ans++;
    }

    cout << ans << endl;

    return 0;
}