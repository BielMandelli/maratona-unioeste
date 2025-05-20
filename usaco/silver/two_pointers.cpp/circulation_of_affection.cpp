#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

signed main() {
    bieo;
    int n,q;
    string s;
    cin >> n >> s >> q;

    while (q--)
    {
        int m;
        char c;
        cin >> m >> c;
        int l = 0, r = 0, ans = 0;
        while (l < n && r < n)
        {
            while (r < n)
            {
                if(s[r] != c){
                    if(m == 0) break;
                    m--;
                }
                r++;
            }
            
            ans = max(ans, r-l);
            m += s[l++] != c;
        }
        
        cout << ans << endl;
    }
    
    return 0;
}
