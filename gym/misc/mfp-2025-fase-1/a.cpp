#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

signed main() {
    bieo;

    int n, m;
    cin >> n >> m;

    vector<int> k(n);

    for(auto &x : k) cin >> x;

    sort(k.begin(), k.end());

    int total = n;
    for (int i = 1, j = 0; i <= m;)
    {
        if(j > n){
            cout << 0 << " ";
            i++;
            continue;
        }

        if(i <= k[j]){
            cout << total << " ";
            i++;
        } else {
            total--;
            j++;
        }
    }

    cout << endl;
        
    return 0;
}
