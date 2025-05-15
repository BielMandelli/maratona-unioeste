#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int e, m, d;
    cin >> e >> m >> d;

    vector<int> odeiax, odeiay, gostax, gostay;

    for (int i = 0; i < m; i++)
    {
        int x,y;
        cin >> x >> y;
        gostax.push_back(x);
        gostay.push_back(y);
    }

    for (int i = 0; i < d; i++)
    {
        int x,y;
        cin >> x >> y;
        odeiax.push_back(x);
        odeiay.push_back(y);
    }

    vector<int> grupos(e+1);
    e = e/3;
    int ans = 0, cur = 0;
    while (e--)
    {
        int x,y,z;
        cin >> x >> y >> z;
        grupos[x] = cur;
        grupos[y] = cur;
        grupos[z] = cur; 
        cur++;
    }

    for (int i = 0; i < m; i++)
        if(grupos[gostax[i]] != grupos[gostay[i]]) ans++;
    
    for (int i = 0; i < d; i++)
        if(grupos[odeiax[i]] == grupos[odeiay[i]]) ans++;
    
    cout << ans << endl;
    
    return 0;
}
