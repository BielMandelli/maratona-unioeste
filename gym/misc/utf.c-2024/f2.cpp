#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define minecraft cin.tie(0)->sync_with_stdio(0);
#define endl "\n"
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
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

int main()
{

    minecraft;

    ll t = 1;
    // cin>>n;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<vector<ll>> psum(2, vector<ll>(n + 1));
        string s;
        cin >> s;

        vector<int> brk(n+1);

        for (ll i = 1; i <= n; i++)
        {
            char c = s[i - 1];
            psum[0][i] += psum[0][i - 1] + (c == 'A');
            psum[1][i] += psum[1][i - 1] + (c == 'C');
            if(i>1) brk[i] += brk[i-1] + (c == s[i-2]);
        }

        ll q;
        cin >> q;
        while (q--)
        {
            ll l, r;
            cin >> l >> r;

            // dbg(q, psum[0][r], psum[0][l - 1], psum[1][r], psum[1][l - 1]);
            if (psum[0][r] - psum[0][l - 1] == 0 || psum[1][r] - psum[1][l - 1] == 0) cout << "SIM" << endl;
            else if (s[l - 1] == 'C') cout << "NAO" << endl;
            else if (s[l-1] == 'A' && brk[r] - brk[l] == 0) cout << "SIM" << endl;
            else cout << "NAO" << endl;
        }
    }

    return 0;
}