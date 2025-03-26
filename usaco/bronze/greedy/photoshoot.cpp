#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long

signed main()
{
    bieo;
    int n;
    string s;
    cin >> n >> s;

    int ans = 0;
    for (int i = n-2; i >= 0; i-=2)
    {
        string sub = s.substr(i, 2);
        if(sub[0] == sub[1]) continue;
        if((sub == "GH" && !(ans%2)) or (sub == "HG" && ans%2)) ans++;
    }
    
    cout << ans << endl;

    return 0;
}