#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

signed main() {
    bieo;
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int mx = 0, sum = 0;
    for(auto &x : a) {
        cin >> x;
        mx = max(mx, x);
        sum+=x;
    }

    int l = mx, r = sum, ans = 0;
    while (l < r)
    {
        int mid = (l+r)/2;
        // cout << "cur" << mid << endl;
        int curSum = 0, g = 0;
        bool valid = true;
        for (int i = 0; i < n; i++)
        {
            if(curSum+a[i] > mid){
                g++;
                curSum = 0;
            }
            curSum += a[i];
        }
        if(curSum > 0) g++;
        if(g > k) valid = false;
        
        if(!valid){
            l = mid+1; 
        } else r = mid;
    }
    
    cout << l << endl;
    
    return 0;
}
