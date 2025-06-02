#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

signed main() {
    bieo;
    int c,g;
    cin >> c >> g;

    if(!c) {
        if(g) cout << "vivo";
        else cout << "morto";
    } else cout << "vivo e morto";
    cout << endl;

    return 0;
}