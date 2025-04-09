#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
 
signed main()
{
    bieo;
    int t;
    cin >> t;
    while (t--)
    {
        int n,k, ans = 0;
        cin >> n >> k;
        while(n >= k){
            if(n%k) {
                ans += n%k;
                n-=n%k;
            }
            else {
                n/=k;
                ans++;
            }
        }

        if(n < k && n != 0) ans += n;

        cout << ans << endl;
    }
}