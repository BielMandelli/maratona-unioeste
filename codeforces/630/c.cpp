#include <bits/stdc++.h>
#define int long long
using namespace std;
 
signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(0);

    int n;
    cin >> n;

    int base = 1;

    for(int i = 1; i <= n; i++){
        if(i == 1) base = 2;
        else base = base*2+2;
    }

    cout << base << endl;

    return 0;
}