#include <bits/stdc++.h>
#define int long long
using namespace std;
 
signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(0);

    int a,b;
    cin >> a >> b;

    vector<int> sa(a), sb(b);
    for (auto &x : sa) cin >> x;
    for (auto &x : sb) cin >> x;

    int j = 0;
    for (int i = 0; i < a; i++)
    {
        if(j == b) break;
        if(sb[j] == sa[i]) j++;
    }
    
    if(j < b) cout << 'N' << endl;
    else cout << 'S' << endl;

    return 0;
}