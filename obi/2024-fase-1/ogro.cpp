#include <bits/stdc++.h>
#define int long long
using namespace std;
 
signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(0);

    int e, d;
    cin >> e >> d;

    if(e > d) cout << e + d << endl;
    else cout << 2 * (d - e) << endl; 

    return 0;
}