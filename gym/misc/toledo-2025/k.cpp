#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long
#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

void solve(){
    string s;
    cin >> s;

    bool can = true;
    for (int i = 0, j = s.size()-1; i < j; i++, j--) {
        if(!can) break;
        if(s[i] != s[j]) can = false;
    }
    
    cout << (can ? "SIM" : "NAO") << endl;
}

signed main(){
    fastio;
    int t;
    cin >> t;
    for (int i=0; i<t; i++) solve();
}