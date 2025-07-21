#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

void solve(){
    int n;
    cin >> n;
    vector<int> a, o(n);
    vector<bool> c(n*2+1);
    for (int i = 0; i < n; i++)
    {
        cin >> o[i];
        c[o[i]] = true;
    }
    
    for(int i = 1; i <= n*2; i++) if(!c[i]) a.push_back(i);

    vector<int> mx(a.begin()+n/2, a.end()), mn(a.begin(), a.begin()+n/2);
    vector<int> omn(o.begin()+n/2, o.end()), omx(o.begin(), o.begin()+n/2);
//     for(auto &x : mx) cout << x << " ";
//     cout << endl;
//     for(auto &x : mn) cout << x << " ";
// cout << endl;
//     for(auto &x : omx) cout << x << " ";
//     cout << endl;
//     for(auto &x : omn) cout << x << " ";

    int ans = 0;
    sort(omx.begin(), omx.end());
    for (int i = 0, j = 0; i < n/2 && j < n/2;)
    {
        if(mx[j] < omx[i]) {
            j++;
            continue;
        }

        i++;
        j++;
        ans++;
    }

    sort(omn.begin(), omn.end());
    for (int i = 0, j = 0; i < n/2 && j < n/2;)
    {
        // cout << h << " " << o[i] << endl;
        if(mn[j] > omn[i]) {
            i++;
            continue;
        }

        i++;
        j++;
        ans++;
    }
    
    cout << ans << endl;
}

signed main()
{
    bieo;
    int t=1;
    // cin >> t;

    while (t--) solve();
    
    return 0;
}