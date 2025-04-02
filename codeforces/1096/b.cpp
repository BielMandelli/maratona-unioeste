#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
const int MOD = 998244353;
 
signed main()
{
    bieo;
    int n;
    string s;
    cin >> n >> s;
    vector<int> freq(26, 0);

    char c;
    bool equal = false;
    for (int i = 0; i < n; i++)
    {
        if(!i) c = s[i];
        if(i+1 == n) if(c == s[i]) equal = true;
    }

    int ans = 0, cl = 0, cr = 0;
    if(equal) {
        for (int i = 0; i < n; i++)
        {
            if(s[i] != c) break;
            cl++;
        }
        cl++;

        for (int i = n-1; i >= 0; i--)
        {
            if(s[i] != c) break;
            cr++;
        }
        cr++;

        ans = (cr * cl) % MOD;
    } else {
        for (int i = 0; i < n-1; i++)
        {
            if(s[i] != s[i+1]) break;
            cr++;
        }
        cr++;

        for (int i = n-1; i > 0; i--)
        {
            if(s[i] != s[i-1]) break;
            cl++;
        }
        cl++;

        ans = (cr+cl+1) % MOD;
    }
    
    cout << ans << endl;
}