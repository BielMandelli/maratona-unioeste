#include <bits/stdc++.h>
using namespace std;
#define beeu cin.tie(0)->sync_with_stdio(0)
#define int long long
const int MOD = 1e9+7;

signed main(){
    beeu;

    int n;
    cin >> n;
    vector<tuple<int,int,int>> c(n);
    vector<bool> invalid(n, false);
    set<int> ans;
    for (int i = 0; i < n; i++)
    {
        int a,b;
        cin >> a >> b;
        get<0>(c[i]) = a;
        get<1>(c[i]) = b;
        get<2>(c[i]) = i;
    }
    
    sort(c.begin(), c.end());

    for (int i = n-1; i >= 0; i--)
    {
        if(invalid[i]) continue;
        for (int j = 0; j < i; j++)
        {
            if(invalid[j]) continue;
            if(get<0>(c[i]) > get<0>(c[j]) && get<1>(c[i]) < get<1>(c[j])) invalid[get<2>(c[j])] = true;
        
    }
    }

    for(int i = 0; i < n; i++) if(!invalid[i]) ans.insert(i); 
    
    cout << ans.size() << endl;
    for (auto x : ans) cout << x+1 << " ";
    cout << endl;

    return 0;
} 
