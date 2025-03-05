#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int ans = 0;

    for (int d = 3; d <= sqrt(n); d += 2) {
        if(!(n%2)) break;
        if (!(n%d)) {
            n -= d;
            ans++;
        }
    }

    if(!(n%2)) ans += n/2;
    else ans++;

    cout << ans << endl;
    
    return 0;
}