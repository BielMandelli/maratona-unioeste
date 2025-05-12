#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

signed main() {
    bieo;
    int n;
    cin >> n;

    int ans = 0;
    bool i = false;
    while(n > 0){
        if(n%2 && n != 1) i = true;
        n /= 2;

        ans++;
    }
    
    if(i) ans++;

    cout << ans << endl;
        
    return 0;
}
