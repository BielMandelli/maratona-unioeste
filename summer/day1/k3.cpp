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
    
    vector<int> a(n+2);
    vector<int> d(n+2, INT_MAX);

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
    }
    

    set<int> left, cur;
    for (int i = 0; i <= n+1; i++)
    {
        left.insert(i);
        cur.insert(i);
    }
    
    for (int i = 0; i < n; i++)
    {
        set<int> del, nwcur;
        for(auto x : cur){
            auto it = left.find(x);
            if(it == left.end()) continue;
            int prv = *prev(it);
            int nxt = *next(it);

            if(a[prv] + a[nxt] > d[x]){
                del.insert(x);
                nwcur.insert(prv);
                nwcur.insert(nxt);
            }
        }
        cout << sz(del) << ' ';
        for(auto it : del) left.erase(it);
        cur = nwcur;
    }
    cout << endl;
}

signed main(){
    fastio;
    int cases = 1;
    cin >> cases;
    for (int i = 0; i < cases; i++){
        solution();
    }
    
}
