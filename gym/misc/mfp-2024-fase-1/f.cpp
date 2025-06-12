#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

signed main() {
    bieo;

    int n;
    cin >> n;

    int ans = 0;
    if(n & 1) ans++;
    if(n & 2) ans++;
    if(n & 4) ans++;
    if(n & 8) ans++;

    cout << ans << endl;
        
    return 0;
}
