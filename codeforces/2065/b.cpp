    #include <bits/stdc++.h>
    #define int long long
    const int MAXX = 1e17;
    using namespace std;

    signed main (){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int t;
        cin >> t;

        while (t--)
        {
            string s;
            cin >> s;

            int ans = s.size();
            for (auto i = 0; i < s.size() - 1; i++)
            {
                if(s[i] == s[i+1]) ans = 1;
            }
            
            cout << ans << endl;
        }

        return 0;
    }