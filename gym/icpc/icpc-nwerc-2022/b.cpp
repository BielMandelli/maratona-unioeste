#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'
double h, r, da, dw;

double f(double x){
    double ha = h - x;
    double cw = x/2, ca = h - ha/2;

    return (ca*da*ha+cw*dw*x)/(ha*da+x*dw);
}

void solve()
{
    cin >> h >> r >> dw >> da;   

    
    double eps = 1e-9; 
    double l = 0, r = h;             
    while (r - l > eps) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        double f1 = f(m1);      
        double f2 = f(m2);      
        if (f1 < f2)
            l = m1;
        else
            r = m2;
        }
    
    cout << setprecision(12) << h-f(l) << endl;
}

signed main()
{
    bieo;
    int t = 1;
    // cin >> t;

    while (t--) solve();

    return 0;
}