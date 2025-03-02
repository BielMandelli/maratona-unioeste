#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;

        vector<pair<int,int>> p(n);

        int aux;
        for (int i = 0; i < n; i++) {
            cin >> p[i].first;
            p[i].second = i;
        }

        int lastDigit = 0, ans = 0;
        
        sort(p.begin(), p.end());

        for (int i = 0; i < n-1; i++) {
            if (p[i].second > p[i + 1].second) ans++;
        }
        
        cout << ans << endl;

    }
    
    return 0;
}