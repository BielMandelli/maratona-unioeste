#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

signed main() {
    bieo;
    int n,q;
    cin >> n >> q;
    vector<int> c(n);
    for(auto &x : c) cin >> x;

    vector<int> p1(n+1),p2(n+1),p3(n+1);
    for (int i = 0; i < n; i++)
    {
        p3[i+1] = p3[i] + (c[i]==3);
        p2[i+1] = p2[i] + (c[i]==2);
        p1[i+1] = p1[i] + (c[i]==1);
    }
    
    while(q--){
        int x,y;
        cin >> x >> y;

        cout << p1[y] - p1[x-1] << " " << p2[y] - p2[x-1] << " " << p3[y] - p3[x-1] << endl;
    }
    
    return 0;
}
