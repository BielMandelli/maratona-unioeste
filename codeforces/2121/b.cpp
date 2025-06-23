#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

void solve()
{
    int n;
    string s;
    cin >> n >> s;

    vector<int> cnt(26);
    for (int i = 0; i < n; i++)
    {
        cnt[s[i]-'a']++;
    }
    
    bool valid = false;
    for (int i = 0; i < 26; i++)
    {
        if(valid) break;
        if(cnt[i] > 1) {
            for (int j = 1; j < n-1; j++)
            {
                if('a'+i == s[j]){
                    valid = true;
                    break;
                }
            }
            
        }
    }

    cout << ((valid) ? "YES" : "NO") << endl;
}

signed main()
{
    bieo;
    int t = 1;
    cin >> t;

    while (t--) solve();

    return 0;
}