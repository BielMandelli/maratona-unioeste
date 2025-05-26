#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

signed main() {
    bieo;

    int t;
    cin >> t;

    while (t--)
    {
        int x;
        cin >> x;

        int q2 = sqrt(x);
        if(q2*q2 == x) {
            if(q2%2) cout << q2/2 << " " << q2/2+1 << endl;
            else cout << q2/2 << " " << q2/2 << endl;
        } else cout << "-1" << endl;
        
    }
    
    return 0;
}
