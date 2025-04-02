#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
vector<int> p(300300, 0);

int check(int l, int r){
    if(r - l == 1) return 0;
    int mid = (l + r)/2;
    int gr = *max_element(p.begin()+l, p.begin()+mid);
    int lw = *max_element(p.begin()+mid, p.begin()+r);
    int ans = 0;
    if(gr > lw){
        ans++;
        for (int i = 0; i < mid-l; i++) swap(p[l+i], p[mid+i]);
    }

    return check(l, mid) + check(mid, r) + ans;
}
 
signed main()
{
    bieo;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) cin >> p[i];
        int ans = check(0, n);
        if(is_sorted(p.begin(), p.begin()+n)) cout << ans << endl;
        else cout << -1 << endl;
    }
}