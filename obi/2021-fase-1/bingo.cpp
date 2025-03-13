#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
#define int long long
const int MOD = 1e9+7;

signed main(){
    fastio;
    
    int n, k, u;
    cin >> n >> k >> u;
    set<int> c[1000];
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

    for (int i = 0; i < u; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(c[j].find(ua[i]) != c[j].end()) c[j].erase(ua[i]);
            if(c[j].empty()) ans.insert(j+1);
            if(!ans.empty()) break;
        }
    }
    
    for(auto x : ans) cout << x << " ";
    cout << endl;
    
}