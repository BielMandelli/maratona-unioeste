#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main() {
    ll t;
    cin>>t;
    while(t--){
        int n, ans = 0;
        cin >> n;
        int aux = n/15;
        ans = aux*3;
        for (int i = 15 * aux; i <= n; i++) {
            if(i % 3 == i % 5) ans++;
        } 
        cout << ans << endl;
    }
    return 0;
}