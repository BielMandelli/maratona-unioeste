#include <bits/stdc++.h>
#define int long long
using namespace std;
 
signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(0);

    int v;
    cin >> v;
    vector<int> a(3);
    for (auto &x : a) cin >> x;

    sort(a.begin(), a.end());

    int ans = 0;
    for (int i = 0; i < 3; i++)
    {
        if(v >= a[i]) {
            v -= a[i];
            ans++;
        } else break;
    }

    cout << ans << endl;

    return 0;
}