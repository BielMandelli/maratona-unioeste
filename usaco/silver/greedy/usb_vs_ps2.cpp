#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

void solve(){
    int a,b,c,m;
    cin >> a >> b >> c >> m;
    deque<int> ps2, usb;
    for (int i = 0; i < m; i++)
    {
        int x;
        string s;
        cin >> x >> s;
        if(s == "USB") usb.push_back(x);
        else ps2.push_back(x);
    }
    
    sort(usb.begin(), usb.end());
    sort(ps2.begin(), ps2.end());

    int ans = 0, cnt = 0;
    for (int i = 0; i < a; i++){
        if(!usb.empty()){
            ans += usb.front();
            usb.pop_front();
            cnt++;
        }
    }

    for (int i = 0; i < b; i++){
        if(!ps2.empty()){
            ans += ps2.front();
            ps2.pop_front();
            cnt++;
        }
    }

    for (int i = 0; i < c; i++){
        int u = 1e14, p = 1e14;
        if(!usb.empty()){
            u = usb.front();
        }
        if(!ps2.empty()){
            p = ps2.front();
        }
        if(!ps2.empty() or !usb.empty()){
            if(p < u){
                ans += p;
                ps2.pop_front();
            } else {
                ans += u;
                usb.pop_front();
            }
            cnt++;
        }
    }
    
    cout << cnt << " " << ans << endl;
}

signed main()
{
    bieo;
    int t=1;
    // cin >> t;

    while (t--) solve();
    
    return 0;
}