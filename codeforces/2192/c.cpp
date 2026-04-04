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

#define int long long
const int INF = 1e17;

int solve(vector<int> a, int n, int h, int k){
    vector<int> psum(n+1);
    
    for (int i = 1; i <= n; i++) psum[i] += psum[i-1] + a[i-1];

    for (int i = 1; i <= n; i++){
        // dbg(psum[i] , h);
        if(psum[i] >= h) return i;
    }
    
    int mag = h/psum[n];
    int t = (n+k) * mag;
    h -= psum[n]*mag;

    if(h == 0) return t - k;
    // dbg(t, h);

    for (int i = 1; i <= n; i++)
        if(psum[i] >= h) return i+t;

    return INF;
}

void solution()
{
    int n,h,k;
    cin >> n >> h >> k;

    vector<int> a(n);
    int sub = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(i && sub == -1){
            if(a[i] > a[i-1]) sub = i-1;
            else if(a[i] < a[i-1]) sub = i;
            else sub = 0;
        }
    }

    int mx = max_element(all(a)) - a.begin();

    int ans = solve(a,n,h,k);

    for (int i = 0; i < min(n-1, 20LL); i++)
    {
        if(mx == i) continue;
        ans = min(solve(a,n,h,k), ans);
        swap(a[i], a[mx]);
    }
    
    cout << ans << endl;
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
