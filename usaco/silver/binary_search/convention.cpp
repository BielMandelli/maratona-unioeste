#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

signed main() {
    // bieo;
    int n, m, c;
    cin >> n >> m >> c;

    vector<int> ct(n);
    for(auto &x : ct) cin >> x;

    sort(ct.begin(), ct.end());

    int l = 0, r = ct[n-1] - ct[0];
    while(l < r){
        int mid = l + (r-l)/2;
        bool fit;
        int bus = 0, cow = 0, fcow = 0;

        while(cow < n){
            if(cow == fcow) bus++;
            if(ct[cow] - ct[fcow] > mid) fcow = cow;
            else if(cow - fcow + 1 == c) fcow = ++cow;
            else cow++;
        }
        
        fit = (bus <= m);

        if(fit) r = mid;
        else l = mid+1;
    }
    
    cout << l << endl;

    return 0;
}
