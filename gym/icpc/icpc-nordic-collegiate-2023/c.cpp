#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) ((int)a.size())

int conv(char c){
    if(c == 'D') return 500;
    if(c == 'C') return 100;
    if(c == 'M') return 1000;
    if(c == 'L') return 50;
    if(c == 'X') return 10;
    if(c == 'V') return 5;
    if(c == 'I') return 1;
    return 0;
}

void solve(){
    string s;
    cin >> s;

    int mx = 0, ans = 0;
    for (int i = s.size()-1; i >= 0; i--)
    {
        mx = max(mx, conv(s[i]));
        if(conv(s[i]) >= mx) ans += conv(s[i]);
        else ans -= conv(s[i]);
        // cout << ans << endl;
    }
    
    cout << ans << endl;
}

signed main(){
    fastio;
    int t;
    cin >> t;
    for (int i=0; i<t; i++) solve();
}