#include <bits/stdc++.h>
using namespace std;

#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) ((int)(a).size())
#define ll long long
#define ld long double

void dbg_out(string s) { cerr << endl; }
template <typename H, typename... T>
void dbg_out(string s, H h, T... t)
{
    do
    {
        cerr << s[0];
        s = s.substr(1);
    } while (sz(s) && s[0] != ',');
    cerr << " = " << h;
    dbg_out(s, t...);
}

#ifdef DEBUG
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

#define int long long
const int INF = 1e9;

void solution()
{
    int n;
    cin >> n;

    vector<int> a(n);
    vector<bool> cnt(n + 1, false);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        cnt[a[i]] = true;
    }

    vector<int> v;
    for (int i = 1; i <= n; i++) if (cnt[i]) v.push_back(i);

    vector<int> dp(n + 1, INF);
    queue<int> q;
        
    dp[1] = 0;
    q.push(1);

    while (!q.empty())
    {
        int x = q.front(); q.pop();
        for (int cur : v)
        {
            int mul = x * cur;
            if (mul > n) break;
            if (dp[mul] > dp[x] + 1)
            {
                dp[mul] = dp[x] + 1;
                q.push(mul);
            }
        }
    }

    if(cnt[1]) dp[1] = 1;
    else dp[1] = -1;

    for (int i = 1; i <= n; i++)
    {
        if (dp[i] == INF) cout << -1 << " ";
        else cout << dp[i] << " ";
    }
    cout << endl;
}

signed main()
{
    fastio;
    int cases = 1;
    cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        solution();
    }
}