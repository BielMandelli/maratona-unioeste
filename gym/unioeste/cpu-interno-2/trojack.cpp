#include <bits/stdc++.h>
#define int long long
using namespace std;
 
signed main(){
    int t;
    cin >> t;
    
    while(t--){
        
        int a, b;
        cin >> a >> b;

        int ans = min(min(a,b), (a+b)/3);

        cout << ans << endl;
    }
    
    return 0;
}