#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
#define int long long
const int MOD = 1e9+7;


signed main(){
    fastio;
    int a,b;
    cin >> a >> b;

    int ans = a;
    while (a >= b)
    {
        ans += a/b;
        if(a%b) {
            int aux = a%b;
            a /= b;
            a += aux;
        }
        else a/= b;
    }
    
    cout << ans << endl;
   
    return 0;
}