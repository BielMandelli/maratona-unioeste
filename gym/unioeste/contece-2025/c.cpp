#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

void solve() {
    int n;
    cin >> n;

    int sum = 0, tsum = 0;
    for (int i = 1; i <= n; i++) tsum += i;
    
    for (int i = 0; i < n-1; i++){
        int x;
        cin >> x;
        sum += x;
    }
    
    cout << tsum - sum << endl;
}


signed main()
{
    bieo;
    int t=1;
    // cin >> t;

    while (t--) solve();
    
    return 0;
}