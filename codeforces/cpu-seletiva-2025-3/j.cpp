#include <bits/stdc++.h>
using namespace std;
#define beeu cin.tie(0)->sync_with_stdio(0)
#define int long long
const int MOD = 1e9+7;

signed main(){
    beeu;

    int y;
    cin >> y;

    if(y%4 == 2) cout << y << endl;
    else if(y%4 == 3) cout << y+3 << endl;
    else if(y%4 == 1) cout << y+1 << endl;
    else cout << y+2 << endl;

    return 0;
} 
