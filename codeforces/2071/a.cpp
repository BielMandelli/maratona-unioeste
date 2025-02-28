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
        if(n%3== 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}