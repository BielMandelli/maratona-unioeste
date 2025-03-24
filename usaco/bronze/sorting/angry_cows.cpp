    #include <bits/stdc++.h>
    using namespace std;
    #define fastio cin.tie(0)->sync_with_stdio(0)
    #define int long long
    const int MOD = 1e9 + 7;

    signed main()
    {
        fastio;
        int n;
        cin >> n;
        vector<int> c(n);
        for(auto &x : c) cin >> x;

        sort(c.begin(), c.end());

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int b = 1, e = 1, st = c[i];
            if(i+1 < n){
                for (int j = i+1; j < n; j++)
                {
                    if(st+b >= c[j]) {
                        while(j+1 < n && st+b >= c[j+1]) {
                            j++;
                            e++;
                        };
                        e++;
                        st = c[j];
                        b++;
                    } else break;
                }
            }

            b = 1, st = c[i];
            if(i-1 > -1){
                for (int j = i-1; j > -1; j--)
                {
                    if(st-b <= c[j]) {
                        while(j-1 > -1 && st-b <= c[j-1]) {
                            e++;
                            j--;
                        }
                        e++;
                        st = c[j];
                        b++;
                    } else break;
                }
            }

            // cout << "start " << c[i] << " expld " << e << " radius " << b << endl;
            
            ans = max(ans, e);
        }
        
        cout << ans << endl;
        
        return 0;
    }