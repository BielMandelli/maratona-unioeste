#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

struct Point {
    int x, y, id;
    bool operator<(const Point& o) const {
        return x < o.x || (x == o.x && y < o.y);
    }
};

long long cross(const Point &O, const Point &A, const Point &B) {
    return (A.x - O.x)*(B.y - O.y) - (A.y - O.y)*(B.x - O.x);
}

vector<Point> convex_hull(vector<Point>& P) {
    int n = P.size(), k = 0;
    sort(P.begin(), P.end());
    vector<Point> H(2*n);

    for (int i = 0; i < n; ++i) {
        while (k >= 2 && cross(H[k-2], H[k-1], P[i]) < 0) k--;  
        H[k++] = P[i];
    }

    for (int i = n-2, t = k+1; i >= 0; --i) {
        while (k >= t && cross(H[k-2], H[k-1], P[i]) < 0) k--; 
        H[k++] = P[i];
    }

    H.resize(k-1); 
    return H;
}

void solve() {
    int n;
    cin >> n;
    vector<Point> pts(n);
    for (int i = 0; i < n; ++i) {
        cin >> pts[i].x >> pts[i].y;
        pts[i].id = i + 1;
    }

    vector<Point> hull = convex_hull(pts);
    set<int> result;
    for (auto& p : hull) result.insert(p.id);

    for (int id : result) cout << id << " ";
    cout << endl;
}

signed main() {
    bieo;
    int t = 1;
    // cin >> t;

    while (t--) solve();
    return 0;
}