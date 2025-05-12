#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

struct point{
    int x,y;
};

int calcDx(point p1, point p2){ return p2.x - p1.x;}
int calcDy(point p1, point p2){ return p2.y - p1.y;}
point dist(point p1, point p2){return {calcDx(p1,p2), calcDy(p1,p2)};}

int length(point a){ return a.x*a.x + a.y*a.y; }

int calcAng(point a, point b){ 
    return (a.x*b.x + a.y*b.y == 0);
}

int parallel(point a, point b){
    if(a.x == 0 or a.y == 0 or b.x == 0 or b.y == 0) return 0;
    if((!(a.x%b.x) && !(a.y%b.y)) or (!(b.y%a.y) && !(b.x%a.x))) return 1;
    return 0;
}
signed main() {
    bieo;
    vector<point> p(4);
    for(auto &x : p) cin >> x.x >> x.y;

    point ab,bc,cd,da,diag1,diag2;
    ab = dist(p[0], p[1]);
    bc = dist(p[1], p[2]);
    cd = dist(p[2], p[3]);
    da = dist(p[3], p[0]);
    diag1 = dist(p[0], p[2]);
    diag2 = dist(p[1], p[3]);

    // cout << ab.x << " " <<  ab.y << " // " << bc.x << " " <<  bc.y << " // " << cd.x << " " << cd.y << " // " << da.x << " " <<  da.y << endl;

    int l1,l2,l3,l4;
    l1 = length(ab);
    l2 = length(bc);
    l3 = length(cd);
    l4 = length(da);
    int d1 = length(diag1);
    int d2 = length(diag2);

    bool equalL = (l1 == l2 && l2 == l3 && l3 == l4);
    bool equalP = (l1 == l3 && l2 == l4);
    bool diagonalsEqual = (d1 == d2);
    bool ang = false;
    if(calcAng(ab, bc) && calcAng(bc, cd) && calcAng(cd, da) && calcAng(da, ab)) ang = true;

    int sidesP = parallel(ab, cd) + parallel(bc, da);

    if(equalL && diagonalsEqual) cout << "square";
    else if(equalL) cout << "rhombus";
    else if(equalP && diagonalsEqual) cout << "rectangle";
    else if(equalP) cout << "parallelogram";
    else if((l1 == l2 && l3 == l4) or (l1 == l4 && l2 == l3)) cout << "kite";
    else if(sidesP == 1) cout << "trapezium ";
    else cout << "none";    

    cout << endl;
    return 0;
}
