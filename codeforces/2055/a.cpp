#include <bits/stdc++.h>
#define int long long
using namespace std;
#define MOD = 1e9 + 7;

signed main(){
    int t;
    cin >> t;

    while(t--)
    {
        int n,a,b;
        cin >> n >> a >> b;

        if(abs(a-b)%2) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    

    return 0;
}