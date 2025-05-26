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
    for(auto &x : a) cin >> x;
    
    sort(a.begin(), a.end());

    int l = 0, r = a[n-1] - a[0];
    while(l < r){
        int mid = (r+l)/2;

        int lb = INT_MIN, curC = 0;
        bool valid = true;
        for (int i = 0; i < n; i++)
        {
            if(abs(a[i] - lb) > mid){
                curC++;
                lb = a[i] + mid;
                if(curC > k){
                    valid = false;
                    break;
                } 
            }
        }
        
        if(valid) r = mid;
        else l = mid+1;
    }

    cout << l << endl;

    return 0;
}
