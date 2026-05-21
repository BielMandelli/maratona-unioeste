#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) ((int)(a).size())
#define ll long long
#define ld long double

void dbg_out(string s) { cerr << endl; }
template <typename H, typename... T>
void dbg_out(string s, H h, T... t)
{
    do{ cerr << s[0]; s = s.substr(1);
    } while (sz(s) && s[0] != ',');
    cerr << " = " << h;
    dbg_out(s, t...);
}

#ifdef DEBUG
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

const int INF = 1e9;
#define int long long

void solution()
{
    int n,h,k;
    cin >> n >> h >> k;

    vector<int> a(n);
    priority_queue<pair<int,int>> pq;
    set<int> remove;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(i) {
            pq.push({a[i], i});
        }
    }

    vector<int> psum(n+1);
    
    for (int i = 1; i <= n; i++) psum[i] += psum[i-1] + a[i-1];

    if(psum[n] >= h){
        for (int i = 1; i <= n; i++)
        {
            auto [v, idx] = pq.top();

            while(!pq.empty() && remove.count(idx) > 0) {
                pq.pop();
                if(pq.empty()) break;
                v = pq.top().first;
                idx = pq.top().second;
            }
            
            dbg((psum[i]-a[i-1]) + v, v);
            if((psum[i]-a[i-1]) + v >= h) {
                cout << i << endl;
                return;
            }

            remove.insert(i);
        }
    } else {
        int mag = h/psum[n];
        dbg(mag);
        int time = mag*(n+k);
        h -= time;

        dbg(time, h);

        for (int i = 1; i <= n; i++)
        {
            auto [v, idx] = pq.top();

            while(!pq.empty() && remove.count(idx) > 0) {
                pq.pop();
                if(pq.empty()) break;
                v = pq.top().first;
                idx = pq.top().second;
            }

            dbg((psum[i]-a[i-1]) + v, v);
            if((psum[i]-a[i-1]) + v >= h) {
                cout << i + time << endl;
                return;
            }

            remove.insert(i);
        }
    }
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
