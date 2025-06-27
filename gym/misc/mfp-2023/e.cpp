#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

void solve() {

    int cnt1 = 0, cnt0 = 0, x;
    for (int i = 0; i < 8; i++)
    {
        cin >> x;
        if(i == 7) break;
        if(x == 1) cnt1++;
    }

    if(!(cnt1%2)) {
        if(x == 0) cout << "N?" << endl;
        else cout << "S" << endl;
    } else {
        if(x == 1) cout << "N?" << endl;
        else cout << "S" << endl;
    }
}

signed main() {
    bieo;
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}