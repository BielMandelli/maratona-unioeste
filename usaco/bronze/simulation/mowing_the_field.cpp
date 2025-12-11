#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define ll long long 
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) ((int) (a).size())
#define ld long double

void dbg_out(string s) {cerr << endl;}
template<typename H, typename ...T>
void dbg_out(string s, H h, T... t){
    do{cerr << s[0]; s = s.substr(1);
    } while(sz(s) && s[0] != ',');
    cerr << " = " << h;
    dbg_out(s, t...);
}

#ifdef DEBUG
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif



void solution(){
    int n;
    cin >> n;

    vector<vector<int>> m(1e4+1, vector<int>(1e4+1, 0));

    int time = 1, posi = 5000, posj = 5000, ans = 1e9;
    for (int i = 0; i < n; i++)
    {
        char d;
        int mv;
        cin >> d >> mv;

        for (int j = 1; j <= mv; j++)
        {
            
            if(d == 'N') posi += 1;
            else if(d == 'S') posi -= 1;
            else if(d == 'W') posj -= 1;
            else if(d == 'E') posj += 1;
            
            dbg(posi, posj, m[posi][posj]);
            if(m[posi][posj]) ans = min(ans, time-m[posi][posj]);
            m[posi][posj] = time;
            
            dbg(i, ans);
            time++;
        }
    }
    
    cout << (ans == 1e9 ? -1 : ans) << endl;
}

signed main(){
    fastio;
    int cases = 1;
    //cin >> cases;
    for (int i = 0; i < cases; i++){
        solution();
    }
    
}
