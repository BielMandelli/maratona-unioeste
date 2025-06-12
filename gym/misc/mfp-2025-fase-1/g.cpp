#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

signed main() {
    bieo;
    string s, a = "", b = "";
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if(i%2) b+= s[i];
        else a+= s[i]; 
    }
    
    cout << a << endl << b << endl;
        
    return 0;
}
