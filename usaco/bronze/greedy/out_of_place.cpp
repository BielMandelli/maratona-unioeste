#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long

bool issort(vector<int> &c){
    for (int i = 0; i < c.size()-1; i++)
    {
        if(c[i] > c[i+1]) return false;
    }
    return true;
}

signed main()
{
    bieo;
    int n;
    cin >> n;
    vector<int> c(n);
    for(auto &x : c) cin >> x;

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if(issort(c)) break;
        int m = 1e9, ma = 0, idx2, idx;
        bool first = true;
        for (int j = n-i; j >= 0; j--)
        {
            if(first) {
                m = c[j];
                idx = j;
                first = false;
            }
            if(c[j] >= ma) {
                ma = c[j];
                idx2 = j;
            }
        }
        if(idx2 == n-i or c[idx] == c[idx2]) continue;
        swap(c[idx], c[idx2]);
        ans++;
    }
    
    
    cout << ans << endl;

    return 0;
}