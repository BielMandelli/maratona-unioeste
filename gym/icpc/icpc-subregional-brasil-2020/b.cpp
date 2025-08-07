#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long
#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

#define DEBUG

void debug_out(string s, int line) { cerr << endl; }
template<typename H, typename... T>
void debug_out(string s, int line, H h, T... t){
    if (s[0] != ',') cerr << "Line(" << line << ") ";
    do{ cerr << s[0]; s = s.substr(1);
    } while (s.size() and s[0] != ',');
    cerr << " = " << h;
    debug_out(s, line, t...);
}

#ifdef DEBUG
#define dbg(...) debug_out(#__VA_ARGS__, __LINE__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> m(11, vector<int>(11));

    bool valid = true;
    for (int i = 0; i < n; i++)
    {
        int d,l,r,c;
        cin >> d >> l >> r >> c;
        l--;

        if(!valid) continue;
        if(r > 10 or c > 10) {
            valid = false;
            continue;
        }
        if(m[r][c]) valid = false;
        m[r][c] = 1;
        if(d) {
            for (int i = r+1; i <= r+l; i++)
            {
                if(i > 10) {
                    valid = false;
                    break;
                }
                if(m[i][c]) valid = false;
                m[i][c] = 1;
            }
        } else {
            for (int i = c+1; i <= c+l; i++)
            {
                if(i > 10) {
                    valid = false;
                    break;
                }
                if(m[r][i]) valid = false;
                m[r][i] = 1;
            }
        }
    }
    
    cout << (valid ? "Y" : "N") << endl;
}

signed main(){
    fastio;
    int t=1;
    //cin >> t;
    for (int i=0; i<t; i++) solve();
}