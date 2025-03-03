#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int ans = 1, sum, cur;
    for (int r = 2; r <= sqrt(n); r++) {
        sum = 1 + r; 
        cur = r;

        while (true) {
            cur *= r; 
            sum += cur;
            if (sum > n) break;
            if (n % sum == 0) ans++;
        }
    }

    int comp;
    for (int d = 1; d <= sqrt(n); d++) {
        if (!(n%d)) {
            if (d >= 3) ans++;

            comp = n/d;
            if (comp != d && comp >= 3) ans++;
        }
    }
    
    cout << ans << endl;

    return 0;
}