#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long

signed main()
{
    bieo;
    int t;
    cin >> t;

    while(t--){
        int n;
        string s;
        cin >> n >> s;

        bool valid = true;
        for (int i = 1; i < n; i++)
        {
            if(s[i] != s[i-1]) valid = false;
        }

        if(valid) {
            cout << s[0] << endl;
            continue;
        }
        
        int l = 0, r = n-1;

        while (l < n-1 && s[l] == s[l+1]) l++;
        while (r > 0 && s[r] == s[r-1]) r--;

        cout << s.substr(l, r - l + 1) << endl;
    }
    
    return 0;
}