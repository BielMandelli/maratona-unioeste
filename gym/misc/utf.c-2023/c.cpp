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

template <class T> 
class Segtree {
public:
    int n;
    vector<T> t;
    vector<T> lazy;
    vector<bool> hasLazy;
    T neutral;

    Segtree(vector<T> arr, T neutral): neutral(neutral) {
        n = 1;
        while (n < (int)arr.size()) n <<= 1;

        t.assign(2*n, neutral);
        lazy.assign(2*n, 0);
        hasLazy.assign(2*n, false);

        for (int i = 0; i < (int)arr.size(); i++)
            t[i+n] = arr[i];
    }

    void apply(int idx, T val) {
        t[idx] = val;
        lazy[idx] = val;
        hasLazy[idx] = true;
    }

    void push(int idx) {
        if (!hasLazy[idx]) return;
        apply(2*idx, lazy[idx]);
        apply(2*idx+1, lazy[idx]);
        hasLazy[idx] = false;
    }

    void update(int l, int r, int idx, int a, int b, T v) {
        if (b < l || r < a) return;

        if (l <= a && b <= r) {
            apply(idx, v);
            return;
        }

        push(idx);
        int m = (a+b)/2;

        update(l, r, 2*idx,   a,   m, v);
        update(l, r, 2*idx+1, m+1, b, v);

        t[idx] = t[2*idx];
    }

    T query(int l, int r, int idx, int a, int b) {
        if (b < l || r < a) return neutral;
        if (l <= a && b <= r) return t[idx];

        push(idx);
        int m = (a+b)/2;

        if (r <= m) return query(l, r, 2*idx, a, m);
        else return query(l, r, 2*idx+1, m+1, b);
    }

    void update(int l, int r, T v) { update(l, r, 1, 0, n-1, v); }
    T query(int p) { return query(p, p, 1, 0, n-1); }
};


void solution(){
    Segtree<int> seg(vector<int>(1e5+123, 0), 0);

    int n, q, x;
    cin >> n >> q >> x;

    map<int, int> mp;
    for (int i = 1; i <= n; i++) mp[i] = -1e9;

    for (int i = 0; i < q; i++)
    {
        int op, j;
        cin >> op >> j;

        if(op == 1) {
            seg.update(1, j, i);
        }
        else {
            bool need = false;
            int cur = seg.query(j);
            dbg(cur);
            if(i-cur > x) need = true;

            cout << (need ? "S" : "N") << endl;
        } 
    }
    
}

signed main(){
    fastio;
    int cases = 1;
    //cin >> cases;
    for (int i = 0; i < cases; i++){
        solution();
    }
    
}
