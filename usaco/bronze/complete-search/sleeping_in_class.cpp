#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
#define int long long
const int MOD = 1e9 + 7;

signed main()
{
    fastio;

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> c(n);
        int sum = 0;
        for(auto &x : c){
            cin >> x;
            sum += x;
        }

        for (int i = 0; i <= sum; i++)
        {
            if(i != 0 && sum % i != 0) continue;

            int cur_sum = 0;
            bool valid = true;
            for(auto x : c){
                cur_sum += x;
                if(cur_sum > i){
                    valid = false;
                    break;
                } else if (cur_sum == i){
                    cur_sum = 0;
                }
            }

            if(valid){
                if(i == 0) cout << 0 << endl;
                else cout << n - (sum / i) << endl;
                break;
            }
        }
    }
    

    return 0;
}