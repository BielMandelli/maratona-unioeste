#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
#define int long long

signed main(){
    fastio;

    int n, q;
    cin >> n >> q;
    vector<int> nums(n);
    for(auto &x : nums) cin >> x;

    sort(nums.begin(), nums.end());

    int t,l,r,k;
    while (q--)
    {    
        cin >> t;
        if(t == 1){
            cin >> k;
            auto pos = lower_bound(nums.begin(), nums.end(), k);
            if(pos == nums.end()) nums.push_back(k);
            else nums[pos-nums.begin()] = k;
        } else {
            cin >> l >> r;

            l = lower_bound(nums.begin(), nums.end(), l) - nums.begin();
            r = upper_bound(nums.begin(), nums.end(), r) - nums.begin();

            cout << r - l << endl;
        }
    }
    
}