#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) (int) (a).size()
#define ll long long
#define ld long double

void dbg_out(string s) { cerr << endl; }
template<typename H, typename... T>
void dbg_out(string s, H h, T... t){
    do { cerr << s[0]; s = s.substr(1);
    } while (sz(s) && s[0] != ',');
    cerr << " = " << h;
    dbg_out(s, t...);
}

#ifdef DEBUG
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS___)
#else
#define dbg(...) 42
#endif

void solve(){
    string s;
    cin >> s;

    queue<int> a,t,p;
    for (int i = 0; i < 10; i++)
    {
        if(s[i] == 'A') a.push(i);
        else if(s[i] == 'T') t.push(i);
        else if(s[i] == 'P') p.push(i);
    }

    bool valid = false;
    while (!a.empty() && !t.empty() && !p.empty())
    {
        if(t.front() < a.front() && a.front() < p.front()){
            valid = true;
            break;
        }

        if(t.front() > a.front()) a.pop();
        else if(a.front() > p.front()) p.pop();
    }
    
    cout << (valid ? 'S' : 'N') << endl;
}

signed main(){
    fastio;
    int t=1;
    //cin >> t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }
    return 0;
}