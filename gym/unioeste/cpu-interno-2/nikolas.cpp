#include <bits/stdc++.h>
#define int long long
using namespace std;
 
signed main(){
    int t;
    cin >> t;
    
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> a;

        char c;
        for (int i = 1; i <= n; i++) {
            cin >> c;
            if (c == 'B') a.push_back(i);
        }

        if(a.empty()) {
            cout << 0 << endl;
            continue;
        }

        int ans = 0, j = 1, i = 0, seq = 0;
        while(i < a.size()) {
            if (j < a.size() && a[j] - a[i] < k) {
                j++;
            }
            else {
                i = j;
                j++;
                ans++;
            }
        }

        cout << ans << endl;

    }
    
    return 0;
}