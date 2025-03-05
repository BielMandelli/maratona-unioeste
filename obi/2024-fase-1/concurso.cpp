#include <bits/stdc++.h>
#define int long long
using namespace std;
 
signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    sort(a.begin(), a.end(), greater<int>());

    for (int i = 0; i < n; i++)
    {
        if(i == k-1) {
            cout << a[i] << endl;
            break;
        }
    }

    return 0;
}