#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

signed main() {
    bieo;
    int n, t;
    cin >> n >> t;
    vector<int> c(n);
    for(auto &x : c) cin >> x;

    int l = 1, r = n, ans = n;
    while(l <= r){
        int m = (l+r)/2;
        priority_queue<int> cnt;
        int bestT = 0, i = 0;
        while(cnt.size() < m && i < n){
            cnt.push(-c[i]);
            i++;
        }

        while(cnt.size()){
            bestT += max(0LL, -cnt.top() - bestT);
            cnt.pop();
            if(i<n){
                cnt.push(-(c[i]+bestT));
                i++;
            }
        }

        if(bestT > t){
            l = m + 1;
        } else {
            r = m-1;
            ans = min(ans, m);
        }
    }
    
    cout << ans << endl;

    return 0;
}
