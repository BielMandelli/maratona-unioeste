#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) ((int) (a).size())
#define ld long double

void dbg_out(string s) {  cerr << endl; }
template<typename H, typename...T>
void dbg_out(string s, H h, T... t){
    do {cerr << s[0]; s = s.substr(1);
    } while (sz(s) && s[0] != ',');
    cerr << " = " << h;
    dbg_out(s, t...);
}

#ifdef DEBUG
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

int query(int x){
    cout << "? " << x << endl;
    cin >> x;
    return x;
}

void solution(){
    int n;
    cin >> n;

    int a = query(1);
    int b = query(n);
    ld target = (a + b) / 2.0;

    int l = 1, r = n;
    while(l < r){
        int mid = (l + r) / 2;
        int v = query(mid);
        if(v < target) l = mid + 1;
        else r = mid;
    }
    int pos = l;

    // Candidatos: pos e pos-1
    vector<int> cand;
    if(pos >= 2 && pos <= n-1) cand.push_back(pos);
    if(pos-1 >= 2 && pos-1 <= n-1) cand.push_back(pos-1);

    int bestY = cand[0];
    ld bestScore = -1;
    for(int y : cand){
        ld sc = sqrtl(fabsl((val[y]-a))) + sqrtl(fabsl((b-val[y])));
        if(sc > bestScore){
            bestScore = sc;
            bestY = y;
        }
    }

    cout << "! 1 " << bestY << " " << n << endl;
}

signed main(){
    // fastio;
    int cases = 1;
    //cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        solution();
    }
}