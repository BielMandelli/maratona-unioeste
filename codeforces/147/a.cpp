#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) (int) (a).size()
#define ll long long
#define ld long double

#define DEBUG

void dbg_out(string s) { cerr << endl; }
template<typename H, typename... T>
void dbg_out(string s, H h, T... t){
    do { cerr << s[0]; s = s.substr(1);
    } while (sz(s) && s[0] != ',');
    cerr << " = " << h;
    dbg_out(s, t...);
}

#ifdef DEBUG
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

bool isMark(char c){
    if(c == ',' or c == '.' or c == '?' or c == '!') return 1;
    return 0;
}

void solve(){
    string s;
    getline(cin, s);
    string ans = "";
    for(int i = 0; i < sz(s); i++){
        if(i && isMark(s[i-1]) && s[i] != ' ') ans.push_back(' ');

        if(s[i] == ' '){
            while(i < sz(s) && s[i+1] == ' ' or isMark(s[i+1])){
                i++;
                if(isMark(s[i])) break;
            } 
        }
        dbg(s[i]);
        ans.push_back(s[i]);
    }

    cout << ans << endl;

}

signed main(){
    fastio;
    int t=1;
    // cin >> t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }
    return 0;
}