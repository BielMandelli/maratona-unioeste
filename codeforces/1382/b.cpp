#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
#define int long long
const int MOD = 1e9+7;

signed main(){
    fastio;

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> p(n);
        for (auto &x : p) cin >> x;

        int win = 0, turn;
        for (int i = 0; i < n; i++)
        {
            if(i == n-1 && p[i] == 1) win = (n+1)%2;
            if(p[i] > 1) {
                win = i%2;
                break;
            }
            
        }
        
        cout << ((!win) ? "First" : "Second") << endl;
    }
    

    return 0;
} 