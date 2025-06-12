#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

signed main() {
    bieo;
    
    int n, t1 = 0, t2 = 0;
    cin >> n;
    while (n--)
    {
        string s, p;
        int t;
        cin >> s >> t >> p;

        if(t == 1) t1 += p[1] - '0';
        else t2 += p[1] - '0';
    }
    
    cout << t1 << " x " << t2 << endl;
        
    return 0;
}
