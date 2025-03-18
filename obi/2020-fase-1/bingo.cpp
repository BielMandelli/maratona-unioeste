#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
#define int long long
const int MOD = 1e9+7;

signed main(){
    fastio;
    
    int n, k, u;
    cin >> n >> k >> u;
    unordered_set<int> c[1000];
    set<int> ans;

    int aux;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cin >> aux;
            c[i].insert(aux);
        }
    }


    vector<int> ua(u);
    for(auto &x : ua) cin >> x;

    int cnt = 0; 
    for (int i = u-1; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            if(c[j].empty()) continue;

            if(c[j].find(ua[i]) != c[j].end()){
                ans.insert(j+1);
                c[j].clear();
                cnt++;
            }
        }

        if(cnt < n) ans.clear();
        else break;
    }
    
    for(auto x : ans) cout << x << " ";
    cout << endl;
    
}