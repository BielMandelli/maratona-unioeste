#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int n, d;
    cin >> n >> d;
    
    vector<int> x(n);
    for (auto &w : x) cin >> w;

    int count = 0, p = 0;

    for (int i = 0; i < n; i++) {
        while (p < n && x[p] - x[i] <= d) {
            p++;
        }
        int m = p - i - 1; 
        if (m >= 2) { 
            count += (1 * m * (m - 1)) / 2; 
        }
    }

    cout << count << endl;
    return 0;
}
