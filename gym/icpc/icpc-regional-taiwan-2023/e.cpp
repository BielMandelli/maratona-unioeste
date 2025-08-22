#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long
#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

#define DEBUG

void debug_out(string s, int line) { cerr << endl; }
template <typename H, typename... T>
void debug_out(string s, int line, H h, T... t)
{
    if (s[0] != ',')
        cerr << "Line(" << line << ") ";
    do
    {
        cerr << s[0];
        s = s.substr(1);
    } while (s.size() and s[0] != ',');
    cerr << " = " << h;
    debug_out(s, line, t...);
}

#ifdef DEBUG
#define dbg(...) debug_out(#__VA_ARGS__, __LINE__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

using ull = unsigned long long;
struct Rect{
    ull x1, y1, x2, y2;
    ull w() const { return x2 - x1; }
    ull h() const { return y2 - y1; }
};

bool overlap(const Rect &a, const Rect &b){
    return max(a.y1, b.y1) < min(a.y2, b.y2);
}

void solve()
{
    ull n, s;
    cin >> n >> s;
    vector<Rect> r(n);

    ull minx = ull(-1), miny = ull(-1);
    ull maxx = 0, maxy = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> r[i].x1 >> r[i].y1 >> r[i].x2 >> r[i].y2;
        minx = min(minx, r[i].x1);
        miny = min(miny, r[i].y1);
        maxx = max(maxx, r[i].x2);
        maxy = max(maxy, r[i].y2);
    }

    vector<vector<pair<int, ull>>> adj(n);
    vector<int> indeg(n, 0);
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (!overlap(r[i], r[j]))
                continue;
            if (r[i].x2 <= r[j].x1)
            {
                adj[i].push_back({j, s});
                indeg[j]++;
            }
            else if (r[j].x2 <= r[i].x1)
            {
                adj[j].push_back({i, s});
                indeg[i]++;
            }
        }
    }

    vector<ull> dist(n, 0);
    queue<int> q;
    for (int i = 0; i < n; ++i)
    {
        dist[i] = r[i].w(); 
        if (indeg[i] == 0) q.push(i);
    }

    ull mxWidth = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        mxWidth = max(mxWidth, dist[u]);
        for (auto [v, sp] : adj[u])
        {
            dist[v] = max(dist[v], dist[u] + sp + r[v].w());
            if (--indeg[v] == 0) q.push(v);
        }
    }

    ull origW = maxx - minx;
    ull origH = maxy - miny;

    ll diff = ((origW >= mxWidth) ? (origW - mxWidth) : -1);
    ull ans = 0;
    if (diff > 0) ans = (origW - mxWidth) * origH;

    cout << ans << '\n';
}

signed main()
{
    fastio;
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; i++) solve();
}