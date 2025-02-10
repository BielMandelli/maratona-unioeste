#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int t;
    cin >> t;

    while(t--){
        int n, ans = 0, aux = 0;

        cin >> n;
        vector<int> nums(n);

        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
            if(nums[i] > 0) aux++;
        }

        while(nums.back() == 0){
            nums.pop_back();
        }

        reverse(nums.begin(),nums.end());

        while(nums.back() == 0){
            nums.pop_back();
        }

        sort(nums.begin(), nums.end());

        if(nums.empty()) {
            cout << 0 << endl;
            continue;
        }

        bool isTrue = binary_search(nums.begin(), nums.end(), 0);

        if(isTrue) cout << 2 << endl;
        else cout << 1 << endl;
    }
    
    return 0;
}