#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

signed main() {
    bieo;
    int x, y, l, lastY = 1e9;
    bool v = true;
    for (int i = 0; i < 4; i++)
    {
        cin >> x >> y;
        if(y != lastY && lastY != 1e9 && v) {
            if(l > lastY) l = lastY - y;
            else l = l - lastY;

            v = false;
        }
        lastY = y;
    }
    
    cout << l*l << endl;
        
    return 0;
}
