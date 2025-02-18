#include <bits/stdc++.h>
#define int long long
const int MAXX = 1e17;
using namespace std;

signed main (){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        if (y == x + 1) {
            cout << "YES" << endl;
        } else {
            int diff = x + 1 - y;
            if (diff >= 0 && diff % 9 == 0) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}