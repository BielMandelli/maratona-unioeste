#include <bits/stdc++.h>
using namespace std;
#define int long long
string s;
vector<int> pen;

bool search(int m, int n, int k){
    int seg = 0, i = 0;
    while(i < n){
        if(s[i] == 'R' && pen[i] > m){
            i++;
            continue;
        }

        bool paint = false;
        while(i < n && !(s[i] == 'R' && pen[i] > m)) {
            if(s[i] == 'B' && pen[i] > m) {
                paint = true;
            }
            i++;
        }
        if(paint) seg++;
    }

    return seg <= k;
}

signed main() {
    int t;
    cin>>t;

    while(t--){
        int n, k;
        cin >> n >> k >> s;

        pen.resize(n);
        int maxPen = 0;

        for (int i = 0; i < n; i++){
            cin >> pen[i];
            maxPen = max(pen[i], maxPen);
        }

        int l = 0, r = maxPen, ans = maxPen;
        while(l <= r){
            int m = l + (r - l) / 2;
            if(search(m, n, k)){
                ans = m;
                r = m - 1;
            } else{
                l = m + 1;
            }
        }

        cout << ans << endl;
    }
    return 0;
}