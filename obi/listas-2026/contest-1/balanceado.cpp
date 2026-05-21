#include <bits/stdc++.h>
using namespace std;
 
signed main()
{
    cin.tie(0)->sync_with_stdio(0);
        
    int n, m, o;
    cin >> n >> m >> o;
    cout << max(n - (m + o), max(m,o)) << endl;
}