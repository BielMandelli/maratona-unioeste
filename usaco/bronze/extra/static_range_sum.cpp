#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,q;
    cin >> n >> q;
    vector<int> nums(n);
    for(auto &x : nums) cin >> x;

    vector<int> psum(n+1);

    for(int i = 1; i <= n; i++){
        psum[i] = nums[i-1] + psum[i-1];
    }

    int l, r;
    while(q--){
        cin >> l >> r;
        if(l != r) cout << psum[r] - psum[l];
        else cout << nums[r];

        cout << endl;
    }
    return 0;
}
