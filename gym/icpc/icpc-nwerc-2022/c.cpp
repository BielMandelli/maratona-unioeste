#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

int mx;

double f(double x){
    int qnt = 0;
    for (int i = 1; i <= x; i++)
    {
        qnt += sqrt(x*x-i*i);
    }
    qnt *= 4;
    return qnt > mx;
}

void solve()
{
    cin >> mx;

    double l = 1, r = 1e5, ans = 0;
    while (r-l > 1e-9)
    {
        double m = (l+r)/2;
        if(f(m)) r = m;
        else l = m;
    }
    
    cout << setprecision(12) << r << endl;
}

signed main()
{
    bieo;
    int t = 1;
    // cin >> t;

    while (t--) solve();

    return 0;
}