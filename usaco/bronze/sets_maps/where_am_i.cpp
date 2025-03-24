#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
#define int long long
const int MOD = 1e9 + 7;

signed main()
{
    fastio;
    int n;
    string s;
    cin >> n >> s;

    for (int k = 1; k <= n; k++)
    {
        bool valid = true;
        unordered_map<string, int> freq;

        for (int i = 0; i <= n - k; i++)
        {
            string sub = s.substr(i, k);
            freq[sub]++;
            if(freq[sub] > 1) valid = false;
        }
        
        if(valid){
            cout << k << endl;
            break;
        }
    }
    
    return 0;
}