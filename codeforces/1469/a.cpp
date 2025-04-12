#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
 
signed main()
{
    bieo;
    int t;
    cin>>t;
    while(t--){
        string s;
        cin >> s;

        if(s.size()%2) {
            cout << "NO" << endl;
            continue;
        }

        bool valid = true;
        int l, r;
        for (int i = 0; i < s.size(); i++)
        {
            if((s[i] == ')' && i == 0) or (s[i] == '(' && i == s.size()-1)) valid = false;
        }
        
        if(valid) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
}