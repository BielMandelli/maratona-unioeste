#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(0);

    double a, b, c, d;
    cin >> a >> b >> c >> d;

    double pS = a/b, pZ = c/d;

    double win = pS/(1-(1-pS)*(1-pZ));

    cout << setprecision(12) << fixed << win << endl;
    return 0;
}
