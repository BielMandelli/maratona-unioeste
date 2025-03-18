#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int n, ans;
    cin >> n;
    vector<int> petals(n);

    for (auto &x : petals) cin >> x;
    ans = n;

    int sum, div;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += petals[k];
            }
            
            div = (j+1) - i;
            if(sum%div) continue;
            int val = sum/div;
            for (int k = i; k <= j; k++)
            {
                if(val == petals[k]) {
                    ans++;
                    break;
                }
            }
            
        }
        
    }
    
    cout << ans << endl;

    return 0;
}