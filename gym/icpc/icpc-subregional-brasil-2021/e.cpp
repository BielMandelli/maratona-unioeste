#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) (int) (a).size()
#define ll long long
#define ld long double
#define pb push_back

typedef long long C;
typedef complex<C> P;
#define X real()
#define Y imag()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

void solution(){
    int n;
    cin >> n;

    queue<int> l, r;
    for (int i = 0; i < n; i++)
    {
        int x,y;
        cin >> x >> y;
        if(y) r.push(x);
        else l.push(x);
    }
    
    dbg(sz(r), sz(l));

    int ans = 0, cur = 0, side = -1;
    while(!r.empty() && !l.empty()){
        int x = r.front();
        int y = l.front();
        
        dbg(side, x, y, cur);
        if(side == -1) {
            side = (x < y ? 0 : 1);
            if(!side) { cur = (cur < x ? x+10 : cur+10); r.pop(); }
            else { cur = (cur < y ? y+10 : cur+10); l.pop();}
            continue;
        }

        if(!side && cur >= x){
            cur = x+10;
            r.pop();
            continue;
        } else {
            cur = y+10;
            l.pop();
            continue;
        }

        side = -1;
    }

    while (!r.empty())
    {
        int x = r.front();
        cur = (cur > x ? x+10 : cur+10); 
        r.pop();
    }

    while (!l.empty())
    {
        int y = l.front();
        cur = (cur > y ? y+10 : cur+10); 
        dbg(y, cur);
        l.pop();
    }
    

    cout << cur << endl;
}

signed main(){
    fastio;
    int t=1;
    //cin >> t;
    for (int i=0; i<t; i++){
        solution();
    }
}