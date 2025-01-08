#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t;
    cin >> t;
    
    while(t--){
        int l,r;

        cin >> l >> r;

        int max_bit_active = 31 - __builtin_clz(l ^ r);
        int a = l | ((1 << max_bit_active) - 1);
        int b = a + 1;
        int c;
        if(a == l) c = r;
        else c = l;

        cout << a << " " << b << " " << c << endl;
    }
    return 0;
}