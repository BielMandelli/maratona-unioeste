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

int queryP(int l, int r){
    cout << "1 " << l << " " << r << endl;
    int x;
    cin >> x;
    return x;
}

int queryA(int l, int r){
    cout << "2 " << l << " " << r << endl;
    int x;
    cin >> x;
    return x;
}

void solution() {
    int n;
    cin >> n;

    int mxA = queryA(1, n);
    int mxP = queryP(1, n);

    int siz = mxA - mxP;

    int ans;
    int l = 1, r = n;
    while (l <= r){
        int mid = l + (r-l)/2;

        int midA = queryA(1, mid);
        int midP = queryP(1, mid);
        
        int diff = midA - midP;

        if(diff > 0){
            r = mid-1;
            ans = mid;
        } else l = mid+1;
    }

    int ans2 = ans+siz;

    cout << "! " << ans << " " << ans2-1 << endl;
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
