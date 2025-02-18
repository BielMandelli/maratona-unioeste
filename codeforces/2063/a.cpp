#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t;
    cin >> t;
    
    while(t--){
        int l, r;
        cin >> l >> r;

        int ans = r - l;
        if(r == 1 && l == 1) ans = 1;
        
        cout << ans << endl;
    }
    
    return 0;
}