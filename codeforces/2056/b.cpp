#include <bits/stdc++.h>
#define int long long
using namespace std;
#define MOD = 1e9 + 7;
static vector<string> g;

bool compare(int u, int v) {
    if (u == v) return false;

    if (g[u - 1][v - 1] == '1') {
        return (u < v);
    } else {
        return (u > v);
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        g.resize(n);
        for(int i = 0; i < n; i++){
            cin >> g[i];
        }

        vector<int> perm(n);
        for (int i = 0; i < n; i++)
        {
            perm[i] = i+1;
        }

        sort(perm.begin(), perm.end(), compare);

        for(int i = 0; i < n; i++){
            cout << perm[i];
            if(i+1 < n) cout << " ";
            else cout << endl;
        }
    }

    
    return 0;
}