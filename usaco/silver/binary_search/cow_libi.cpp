#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

struct point
{
    int x,y,t;
    bool operator<(const point& p) const {
        return t < p.t;
    }
};

bool calc(point p1, point p2){
    int dt,dx,dy;
    dx = p1.x - p2.x;
    dy = p1.y - p2.y;
    dt = p1.t - p2.y;
    return dx*dx+dy*dy > dt*dt;
}

signed main() {
    bieo;
    int g, n;
    cin >> g >> n;
    vector<point> c(n), gr(g);
    for(auto &x : gr) cin >> x.x >> x.y >> x.t;
    for(auto &x : c) cin >> x.x >> x.y >> x.t; 
    
    sort(gr.begin(), gr.end());

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        bool valid = true;
        auto it = upper_bound(gr.begin(), gr.end(), point{0,0, c[i].t});

        if(it != gr.end()) if(calc(c[i], *it)) valid = false;
        if(it > gr.begin()) if(calc(c[i], *(it-1))) valid = false;

        if(!valid) ans++;
    }

    cout << ans << endl;
    
    return 0;
}
