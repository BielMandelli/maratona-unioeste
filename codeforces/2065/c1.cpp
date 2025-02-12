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
            int n,m;
            cin >> n >> m;
            vector<int> a(n),b(m);

            for(auto &x: a) cin >> x;
            for(auto &x: b) cin >> x;

            bool isTrue = true;
            int minor, maxi;
            for (int i = 1, j = 0; i < n; i++)
            {
                if(a[i] > a[i-1]) {
                    minor = min(a[i], b[j] - a[i]);
                    a[i] = minor;
                }
            }

            for (int i = 0, j = 0; i < n; i++)
            {
                if(i == n-1) break;
                if(a[i] > a[i+1]) isTrue = false;
            }

            if(isTrue) cout << "YES" << endl;
            else cout << "NO" << endl;
            
        }

        return 0;
    }