#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,k;
    cin >> n >> k;

    vector<int> d(n);
    vector<int> freq(2*1e5);

    for(auto &x : d) cin >> x;

    int l = 0, r = 0, bestR = 0, bestL = 0, unique = 0, maxLen = 0;
    while(r < n)
    {   
        if(freq[d[r]] == 0) unique++;
        freq[d[r]]++;

        while (unique > k) {
            freq[d[l]]--;
            if (freq[d[l]] == 0) unique--;
            l++;
        }

        // cout << "r: " << r << endl;
        // cout << "maxLen: " << maxLen << " r - l: " << r - l << endl;
        if (r - l + 1> maxLen) {
            maxLen = r - l + 1;
            bestL = l+1;
            bestR = r+1;
        }

        r++;
    }

    cout << maxLen << endl;
    cout << bestL << " " << bestR << endl;
    
    return 0;
}
