#include <bits/stdc++.h>
using namespace std;

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int n, res;
    cin >> n;
    res = (n-3)%8;
    cout << ((res == 3) ? 1 : (res == 4) ? 2 : 3) << endl;
}