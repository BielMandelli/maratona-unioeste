#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long

signed main()
{
    bieo;
    int n;
    string a,b;
    cin >> n >> a >> b;

    bool valid = false;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if(a[i] != b[i]){
            if(!valid) {
                ans++;
                valid = true;
            }
        } else valid = false;
    }

    cout << ans << endl;
    
    return 0;
}