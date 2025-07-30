#include <bits/stdc++.h>
using namespace std;
#define ll long long

signed main() {
    int n, k, q;
    cin >> n >> k >> q;

    vector<int> diff(2e5+2), psum(2e5+2), valid(2e5+2);
    int l,r;
    for (int i = 0; i < n; i++){
        cin >> l >> r;

        diff[l]++; diff[r+1]--;
    }

    for (int i = 1; i <= 2e5+2; i++) psum[i] = psum[i-1] + diff[i];
    for (int i = 1; i <= 2e5+2; i++) valid[i] = valid[i-1] + (psum[i] >= k);
    
    while (q--){
        cin >> l >> r;
        cout << valid[r]-valid[l-1] << endl;
    }
    
    return 0;
}