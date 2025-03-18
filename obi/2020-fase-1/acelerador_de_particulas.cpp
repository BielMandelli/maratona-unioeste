#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
#define int long long
const int MOD = 1e9+7;

signed main(){
    fastio;
    
    int n, res;
    cin >> n;
    res = (n-3)%8;
    cout << ((res == 3) ? 1 : (res == 4) ? 2 : 3) << endl;
}