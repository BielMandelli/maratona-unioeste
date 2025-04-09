#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long

signed main() {
    bieo;
    int t;
    cin >> t;

    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        if(k>3){
            cout << 0 << endl;
            continue;
        }

        if(k == 1) cout << 1 << endl;
        else if(k == 2) cout << m/n + min(n-1, m) << endl;
        else if(k == 3) cout << m - m/n - min(n-1, m)  << endl;
    }

    return 0;
}
