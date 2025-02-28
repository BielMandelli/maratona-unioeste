#include <bits/stdc++.h>
using namespace std;
#define int long long
 
signed main() {
    int t;
    cin>>t;

    while(t--){
        int n, x, k;
        string s;

        cin >> n >> x >> k >> s;

        int minDist = 0, ans = 0, cur = x;
        for(int i = 0; i <= n; i++){
            if(cur == 0) {
                ans++;
                break;
            }
            if(i == n) break;
            if(s[i] == 'L') cur--;
            else cur++;

            minDist++;
        }

        k -= minDist;

        if(ans > 0){
            minDist = 0, cur = 0;
            bool isFirst = true;
            for(int i = 0; i <= n; i++){
            
            if(cur == 0 && !isFirst) {
                ans += k/minDist;
                break;
            } else isFirst = false;

            if(i == n) break;

            if(s[i] == 'L') cur--;
            else cur++;


            minDist++;
            }

            
        }

        cout << ans << endl;
        
    }
    return 0;
}