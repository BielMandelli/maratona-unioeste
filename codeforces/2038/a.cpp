#include <bits/stdc++.h>
#define int long long
using namespace std;
 
signed main(){
    int n, k, sum = 0;
    cin >> n >> k;
    vector<int> a(n), b(n), c(n);

    for(auto &x: a) cin >> x;
    for(auto &x: b) cin >> x;
    
    for (int i = 0; i < n; i++) sum += a[i]/b[i];

    if (sum < k) {
        for (int i = 0; i < n; i++) {
            if(i == n-1) {
                cout << "0" << endl;
                return 0;
            }
            else cout << "0 ";
            
        }
    }

    int nI = n;
    while(nI--){
        c[nI] = min(k, a[nI]/b[nI]);
        k -= c[nI];
    }

    for (int i = 0; i < n; i++) {
        if(i == n-1) cout << c[i] << endl;
        else cout << c[i] << " ";
    }
    
    return 0;
}