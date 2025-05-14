#include <bits/stdc++.h>
using namespace std;
#define ll long long

signed main(){
    
    int n, k, u;
    cin >> n >> k >> u;
    vector<vector<int>> c(1000);
    vector<int> ans;

    int aux;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cin >> aux;
            c[i].push_back(aux);
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

            if(find(c[j].begin(), c[j].end(), ua[i]) != c[j].end()){
                ans.push_back(j+1);
                c[j].clear();
                cnt++;
            }
        }

        if(cnt < n) ans.clear();
        else break;
    }
    
    sort(ans.begin(), ans.end());
    
    for(auto x : ans) cout << x << " ";
    cout << endl;
    
}