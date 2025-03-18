#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
#define int long long
const int MOD = 1e9+7;

signed main(){
    fastio;
    int n, m;
    pair<int,int> ir;

    cin >> n >> m >> ir.first >> ir.second;

    set<int> temp, inf = {ir.first};
    int x, aux;
    for (int i = 0; i < m; i++)
    {
        temp.clear();
        cin >> x;
        for (int j = 0; j < x; j++)
        {
            cin >> aux;
            temp.insert(aux);
        }

        if(i < ir.second-1) continue;

        for (auto it = inf.begin(); it != inf.end(); it++)
            if(temp.count(*it) > 0) {
                for (auto j = temp.begin(); j != temp.end(); j++) inf.insert(*j);
                break;
            }
    }

    cout << inf.size() << endl;
}