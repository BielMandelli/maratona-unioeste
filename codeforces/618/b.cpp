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
    vector<int> p;
    set<int> ps;

    int aux;
    for (int i = 0; i < n; i++)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            p.push_back(aux);
            if(!aux) continue;
            ps.insert(aux);
        }
        if(ps.size() == n-1) break;

        ps.clear();
        p.clear();
    }

    int miss;
    for (int i = 1; i <= n; i++)
    {
        if(!ps.count(i)) {
            miss = i;
            break;
        }
    }
    
    

    for (int i = 0; i < n; i++)
    {
        if(p[i] == 0) cout << miss << " ";
        else cout << p[i] << " ";
    }
    cout << endl;
    
    
    
    return 0;
}