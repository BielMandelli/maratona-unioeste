#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

signed main() {
    bieo;

    int n;
    cin >> n;

    n *= 8*1e6;
    int qb = 1, ans = 0;
    while (qb < n)
    {
        qb <<= 1;
        ans++;
    }
    
    cout << ans << endl;
    
    return 0;
}
