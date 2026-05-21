#include <bits/stdc++.h>
using namespace std;
 
signed main() {
    cin.tie(0)->sync_with_stdio(0);

    double c, d, t, aux;
    cin >> c >> d >> t;

    cout << setprecision(1) << fixed;

    aux = d/c;
    aux = aux - t;
    if(aux <= 0) cout << 0.0 << endl;
    else cout << aux << endl;

    return 0;
}