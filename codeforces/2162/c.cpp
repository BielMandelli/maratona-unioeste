#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) ((int)(a).size())
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

int msb(int n) {
    if (n == 0) return -1;
    return 31 - __builtin_clz(n);
}

void solution() {
    int a, b;
    cin >> a >> b;

    if (a == b) {
        cout << 0 << endl;
        return;
    }

    if (msb(b) > msb(a)) {
        cout << -1 << endl;
        return;
    }

    int req = a ^ b;
    if (req <= a) {
        cout << 1 << endl;
        cout << req << endl;
        return;
    }

    
    int x1 = a ^ (a | b);
    int orr = a | b; 

    int x2 = orr ^ b;
    
    cout << 2 << endl;
    cout << x1 << " " << x2 << endl;
}

signed main()
{
    fastio;
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        solution();
    }
}
