#include <bits/stdc++.h>
#define int long long
const int MAXX = 1e17;
using namespace std;

signed main (){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        bool isTrue = true;
        cin >> n;
        vector<int> a(n);
        for(auto &x : a) cin >> x;

        sort(a.begin(), a.end());
        int maxi = 0;
        for (int i = 0; i < n; i+=2)
        {
            if(max(maxi, a[i]) != max(maxi, a[i+1])){
                isTrue = false;
                break;
            }
            maxi = max(maxi, a[i]) + 1;
        }

        if(isTrue) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}