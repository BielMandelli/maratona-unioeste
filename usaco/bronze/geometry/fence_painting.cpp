#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long

signed main()
{
    bieo;
    int a,b,c,d;
    cin >> a >> b >> c >> d;

    int ans;
    if(d < a or c > b) ans = b-a + d-c; 
    else ans = max(b,d) - min(a,c);

    cout << ans << endl;
    
    return 0;
}