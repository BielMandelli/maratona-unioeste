#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
vector<int> type;

signed main()
{
    bieo;
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> c(m);
    vector<int> ans(n, 0);
    for(auto &x : c) {
        cin >> x.first >> x.second;
        x.first--;
        x.second--;
        if(x.first > x.second) swap(x.first, x.second);
    }
    
    for (int i = 0; i < n; i++)
    {
        int b = 1;
        while (b <= 4)
        {
            bool confl = false;
            for(auto x : c){
                if(ans[x.first] == b && x.second == i){
                    confl = true;
                    break;
                }
            }

            if(!confl) break;
            b++;
        }
        ans[i] = b;
    }
    

    for(auto x : ans) cout << x;
    cout << endl;

    return 0;
}