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
    int n;
    string s;
    
    cin >> n >> s;

    int cnt1 = 0, cnt0 = 0;
    for (int i = 0; i < n; i++)
    {
        if(s[i] == '1') cnt1++;
        else cnt0++;
    }

    if(cnt1 == 0) {
        cout << 0 << endl;
        return;
    }

    if(n == 1) {
        cout << -1 << endl;
        return;
    }
    
    if(cnt1%2 == 0) {
        cout << cnt1 << endl;
        for (int i = 0; i < n; i++)
        {
            if(s[i] == '1') cout << i+1 << ' ';
        }
        cout << endl;
        return;
    } else if(cnt0%2) {
        cout << cnt0 << endl;
        for (int i = 0; i < n; i++)
        {
            if(s[i] == '0') cout << i+1 << ' ';
        }
        cout << endl;
        return;
    }

    cout << -1 << endl;
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
