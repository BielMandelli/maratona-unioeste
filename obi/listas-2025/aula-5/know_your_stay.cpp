#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t;
    cin >> t;

    while (t--)
    {
        int n,m;
        cin >> n >> m;

        vector<int> d(n);
        for (int i = 0; i < n; i++){
            cin >> d[i];
        }
        
        vector<ll> psum(n+1);
        for (int i = 1; i <= n; i++){
            psum[i] = psum[i-1] + d[i-1];
        }
        
        for (int i = 0; i < m; i++)
        {
            int sd, sm, ed, em;
            cin >> sd >> sm >> ed >> em;

            sm--; em--;
            int curM = d[sm] - sd + 1;
            int between = psum[em] - psum[sm + 1];
            int ans = curM + between + ed;

            if(ans <= 0) ans += psum[n];
            cout << ans << endl;
        }
    }
    
    return 0;
}