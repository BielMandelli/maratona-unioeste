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
set<int> ans;

template <class T> class Segtree{
public:
    int n;
    vector<T> t;
    vector<T> lazy;
    int neutral = -1;
    Segtree(vector<int> arr, T neutral){
        n=1;
        while (n<sz(arr)) n <<= 1;
        t.resize(2*n, neutral);
        lazy.resize(2*n);
        for (int i=0; i<sz(arr); i++) t[i+n] = arr[i];
        for (int i=n-1; i; i--) t[i] = comb(t[2*i], t[2*i+1]);
    }

    T comb(T l, T r){
        return max(l, r);
    }

    void apply(int idx){
        t[idx] = lazy[idx];
        lazy[idx] = 0;
    }
    
    void prop(int idx){
        if (!lazy[idx]) return;
        if (idx < n){
            lazy[2*idx] = lazy[idx];
            lazy[2*idx+1] = lazy[idx];
        }
        apply(idx);
    }

    void update(int l, int r, int idx, int a, int b, T v){
        prop(idx);
        if (b < l || r < a) return;
        if (a <= l && r <= b){
            lazy[idx] = v;
            prop(idx);
            return;
        }
        int m = (l+r)/2;
        update(l, m, 2*idx, a, b, v);
        update(m+1, r, 2*idx+1, a, b, v);
        t[idx] = comb(t[2*idx], t[2*idx+1]);
    }

    T query(int l, int r, int idx, int a, int b){
        if (b < l || r < a) return neutral;
        prop(idx);
        if (a <= l && r <= b) {
            return t[idx];
        }
        int m = (l+r)/2;
        return comb(query(l, m, 2*idx, a, b), query(m+1, r, 2*idx+1, a, b));
    }

    void update(int l, int r, T v){
        update(0, n-1, 1, l, r, v);
    }

    T query(int l, int r){
        return query(0, n-1, 1, l, r);
    }
};


void solution(){
    int n;
    cin >> n;
    ans.clear();

    vector<pair<int,int>> p(n);

    int id = 1;
    for(auto &x : p) {
        cin >> x.first >> x.second;
    }
    
    vector<int> coords;
    for(auto &x : p){
        coords.push_back(x.first);
        coords.push_back(x.second);
        coords.push_back(x.second + 1);
    }
    vector<int> a(sz(coords), -1);
    Segtree<int> seg(a, -1);

    sort(all(coords));
    coords.erase(unique(all(coords)), coords.end());

    for(auto &x : p){
        int l = lower_bound(all(coords), x.first) - coords.begin();
        int r = lower_bound(all(coords), x.second) - coords.begin();
        seg.update(l, r, id);
        id++;
    }
    
    for(int i = 0; i < coords.size(); i++){
        int val = seg.query(i, i);
        if(val != -1) ans.insert(val);
    }
    cout << sz(ans) << endl;
}

signed main(){
    fastio;
    int cases = 1;
    cin >> cases;
    for (int i = 0; i < cases; i++){
        solution();
    }
    
}
