#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
 
signed main()
{
    bieo;
        
    int n, k;
    cin >> n >> k;
    vector<int> psum(1e6);
    psum[0] = 1;
    int sum = 0, ans = 0;
    for (int i = 0, x; i < n; i++)
    {
        cin >> x;

        sum += x;

        if(sum >= k) ans += psum[sum-k];
        psum[sum]++;
    }
    
    cout << ans << endl;
}