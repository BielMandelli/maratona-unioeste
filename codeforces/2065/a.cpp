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

            s.erase(s.end()-2, s.end());
            s += 'i';

            cout << s << endl;
        }

        return 0;
    }