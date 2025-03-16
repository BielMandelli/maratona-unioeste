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
        string s, r;
        cin >> n >> s >> r;

        int c1 = 0, c0 = 0;
        bool valid = true;
        for (auto &x : s){
            if(x == '1') c1++;
            else c0++;
        }

        for (int i = 0; i < n-1; i++)
        {
            if(!c1 or !c0) {
                valid = false;
                break;
            }

            if(r[i] == '1') c0--;
            else c1--;
        }
    
        cout << ((valid) ? "YES" : "NO") << endl;
    }

    return 0;
}