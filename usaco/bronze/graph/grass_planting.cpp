#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
vector<int> type;

signed main()
{
    bieo;
    int n;
    cin >> n;

    type.resize(n+1, 1);
    
    int x,y;
    for(int i = 0; i < n-1; i++){
        cin >> x >> y;
        type[x]++;
        type[y]++;
    }

    int maxG = 0;
    for(int i = 1; i <= n; i++) maxG = max(type[i], maxG);

    cout << maxG << endl;

    return 0;
}