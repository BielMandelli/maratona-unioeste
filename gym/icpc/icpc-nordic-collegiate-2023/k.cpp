#include <bits/stdc++.h>
using namespace std;
// #define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

int buff(int x){
    cout << "buf[" << x << "]" << endl;
    int y;
    cin >> y;
    return y;
}

signed main()
{
    // bieo;
    
    int l,r = 2;
    while (buff(r*2-1)) r = r*2;
    l = r+1;
    
    int ans = r;
    r = r*2-1;
    while (l <= r)
    {
        int m = (l+r)/2;
        if(buff(m-1)){
            ans = m;
            l = m+1;
        } else r = m-1;
    }
    
    cout << "strlen(buf) = " << ans << endl;

    return 0;
}