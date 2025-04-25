#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

int ch(int w){
    return (w == 1) ? 2 : 1;
}

signed main() {
    bieo;
    
    int n;
    cin >> n;

    vector<int> v(n);
    for(auto &x : v) cin >> x;

    int w = 2;

    for (int i = 0; i < n; i++)
    {
        if(v[i] == 1) {
            cout << w << endl;
            continue;
        };

        if(!(v[i]%2)) w = ch(w);

        cout << w << endl;
    }
        
    return 0;
}
