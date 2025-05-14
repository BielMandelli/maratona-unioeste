#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'


signed main() {
    bieo;
    int n,w;
    cin >> n >> w;

    vector<tuple<int,int,int>> wvs;

    while (n--)
    {
        char c;
        cin >> c;
        if(c == '!'){
            int x,y,z;
            cin >> x >> y >> z;
            wvs.push_back({x,y,z});
        }
        else {
            int pos;
            cin >> pos;

            int ans = 0;
            for(auto [p, l, a] : wvs){
                if(pos < p) continue;
                if(pos > p + l - 1) continue;

                int mod = p%4, modm = (p+2)%4;
                if(pos%4 == mod) ans+=a;
                else if(pos%4 == modm) ans-=a;
            }

            cout << ans << endl;
        }
    }
        
    return 0;
}
