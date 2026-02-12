#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define ii pair<int,int>
#define iii pair<int,ii>

const int INF = 1e18;

struct segtree{
    struct node{
        int sum;
    };

    int size;
    vector<node> nodes;
    vi lazy;
    node NEUTRAL = {0};

    node single(int v){
        return {v};
    }

    node merge(node a, node b){
        return {a.sum +b.sum};
    }

    void init(int n){
        size = 1;
        while(size < n) size <<= 1;
        nodes.assign(2*size-1,NEUTRAL);
        lazy.assign(2*size-1,0);
    }

    void flip(int l, int r){
        rangeUpdate(l,r,1,0,0,size);
    }

    void set1(int l, int r){
        rangeUpdate(l,r,2,0,0,size);
    }

    void set0(int l, int r){
        rangeUpdate(l,r,3,0,0,size);
    }

    void rangeUpdate(int l, int r, int v, int x, int lx, int rx){
        unlazy(x,lx,rx);
        if (rx-lx < 1 || rx <= l || lx >= r) return;
        if (l <= lx && rx <= r) return propagate(x,lx,rx,v);
        int mx = (lx+rx)/2;
        rangeUpdate(l,r,v,2*x+1,lx,mx);
        rangeUpdate(l,r,v,2*x+2,mx,rx);
        nodes[x] = merge(nodes[2*x+1], nodes[2*x+2]);
    }

    void unlazy(int x, int lx, int rx){
        // cout << "unlazying " << lx << ' ' << rx << ' ' << lazy[x] << endl;
        if (lazy[x]){
            propagate(x,lx,rx,lazy[x]);
            lazy[x] = 0;
        }
    }

    void propagate(int x, int lx, int rx, int v){
        if (v == 1) nodes[x].sum = (rx-lx)-nodes[x].sum;
        if (v == 2) nodes[x].sum = rx-lx;
        else if (v == 3) nodes[x].sum = 0;
        if (rx-lx > 1){
            int mx = (lx+rx)/2;
            // unlazy(2*x+1,lx,mx);
            // unlazy(2*x+2,mx,mx);
            if (v==1){
                if (lazy[2*x+1]==1) lazy[2*x+1]=0;
                else if (lazy[2*x+1] == 2) lazy[2*x+1] = 3;
                else if (lazy[2*x+1] == 3) lazy[2*x+1] = 2;
                else lazy[2*x+1] = 1;

                if (lazy[2*x+2]==1) lazy[2*x+2]=0;
                else if (lazy[2*x+2] == 2) lazy[2*x+2] = 3;
                else if (lazy[2*x+2] == 3) lazy[2*x+2] = 2;
                else lazy[2*x+2] = 1;
            }else {
                lazy[2*x+1]=v;
                lazy[2*x+2]=v;
            }
        }
    }

    int query(){
        return query(0,0,size);
    }

    int query(int x,int lx, int rx){
        unlazy(x,lx,rx);
        // cout << lx << ' ' << rx << ' ' << nodes[x].sum << endl;
        if (rx-lx == 1) return lx;
        int mx = (lx+rx)/2;
        unlazy(2*x+1,lx,mx); unlazy(2*x+2,mx,rx);
        node left = nodes[2*x+1];
        node right = nodes[2*x+2];
        // cout << "left is " << left.sum << " right is " << right.sum << endl;
        if (left.sum == mx-lx) return query(2*x+2,mx,rx);
        return query(2*x+1,lx,mx);
    }
};

void solve(){
    map<int,int> coord, inv;
    int n; cin >> n;
    vector<iii> queries(n);
    for (auto &[t,lr] : queries){
        auto &[l,r] = lr;
        cin >> t >> l >> r;
        l--,r--;
        if (l-1 >= 0) coord[l-1] = 0;
        coord[l] = 0;
        coord[l+1] = 0;
        if (r-1 >= 0) coord[r-1] = 0;
        coord[r] = 0;
        coord[r+1] = 0;
    }

    int cnt = 0;
    for (auto &[f,s] : coord) {
        s = cnt;
        inv[cnt] = f;
        cnt++;
    }



    segtree seg;
    seg.init(cnt+1);

    int one = 0;

    for (auto &[t,lr] : queries){
        auto &[l,r] = lr;
        // processa a query
        if (t == 1) seg.set1(coord[l],coord[r+1]);
        if (t == 2) seg.set0(coord[l],coord[r+1]);
        if (t == 3) seg.flip(coord[l],coord[r+1]);
        // cout << "query\n";
        int id = seg.query();
        // cout << endl;
        // cout << id << ' ';
        if (l == 0 && t == 1) one = 1;
        if (l == 0 && t == 2) one = 0;
        if (l == 0 && t == 3) one^=1;
        if (one == 0) cout << 1 << endl;
        else cout << inv[id]+1 << '\n';
    }
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}

