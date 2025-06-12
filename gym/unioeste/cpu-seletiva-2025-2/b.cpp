#include <bits/stdc++.h>
using namespace std;
#define beeu cin.tie(0)->sync_with_stdio(0)
#define int long long
const int MOD = 1e9+7;

signed main(){
    beeu;

    int n;
    cin >> n;
    vector<int> arr(n), ans;
    unordered_set<int> freq;
    for(auto &x : arr) cin >> x;

    unordered_set<int> window;
    int start = 0, minLen = 1e9;

    for (int end = 0; end < n; end++) {
        while (window.find(arr[end]) != window.end()) {
            window.erase(arr[start]);
            minLen = min(minLen, end - start + 1);
            start++;
        }

        window.insert(arr[end]);
    }

    cout << ((minLen == 1e9) ? -1 : minLen) << endl;

    return 0;
} 

