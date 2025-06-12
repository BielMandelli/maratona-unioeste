#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

signed main() {
    bieo;
    int n;
    cin >> n;

    string s, t;
    cin >> s >> t;

    int cnts = 0, cntt = 0;
    for (int i = 0; i < n; i++)
    {
        if(s[i] == '*' && t[i] != '*') cntt++; 
        if(s[i] == '*') cnts++;
    }
    
    double ans = (double) cntt/ (double) cnts;

    cout << setprecision(2) << fixed;
    cout << ans << endl;
    return 0;
}