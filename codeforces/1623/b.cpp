#include <bits/stdc++.h>
#define int long long
using namespace std;
 
signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(0);
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<vector<bool>> visited(n + 1, vector<bool>(n + 1));
        vector<int> l(n), r(n);

        for (int i = 0; i < n; i++) {
            cin >> l[i] >> r[i];
            visited[l[i]][r[i]] = true;
        }

        for (int i = 0; i < n; i++) {
            for (int d = l[i]; d <= r[i]; d++) {
                if ((d == l[i] or visited[l[i]][d - 1]) and (d == r[i] or visited[d + 1][r[i]])) {
                    cout << l[i] << ' ' << r[i] << ' ' << d << endl;
                    break;
                }
            }
        }

    }
    
    
    return 0;
}