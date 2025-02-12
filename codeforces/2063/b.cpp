#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t;
    cin >> t;

    while (t--) {
        int n, l, r;
        cin >> n >> l >> r;
        l--; 
        vector<int> original(n);

        for (int i = 0; i < n; i++) {
            cin >> original[i];
        }

        vector<int> b = original;
        sort(b.begin() + l, b.end());

        vector<int> c = original;
        sort(c.begin(), c.begin() + r, greater<int>());

        int sum_b = 0, sum_c = 0;
        
        for (int i = l; i < r; i++) {
            sum_b += b[i];
            sum_c += c[i];
        }

        cout << min(sum_b, sum_c) << endl;
    }
    
    return 0;
}