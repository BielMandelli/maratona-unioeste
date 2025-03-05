#include <bits/stdc++.h>
#define int long long
using namespace std;
 
signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(0);

    int h, m, s, t;
    cin >> h >> m >> s >> t;

    s+= t;
    m+= s/60;
    s%=60;

    h += m/60;
    m %= 60;

    h%=24;

    cout << h << endl << m << endl << s << endl;
    return 0;
}