#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
 
signed main()
{
    bieo;
        
    int n, m, o;
    cin >> n >> m >> o;
    cout << max(n - (m + o), max(m,o)) << endl;
}