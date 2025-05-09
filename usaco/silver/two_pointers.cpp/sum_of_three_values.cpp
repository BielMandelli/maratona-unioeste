#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

signed main() {
    bieo;
    int n, x;
    cin >> n >> x;
    vector<pair<int,int>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i+1;
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++)
    {
        int l,r;
        l = 0;
        r = n-1;
        while (l != r)
        {
            int sum;
            sum = x - a[i].first;
            if(l != i && r != i && a[l].first + a[r].first == sum){
                cout << a[l].second << " " << a[i].second << " " << a[r].second << endl;
                return 0; 
            }

            if(a[l].first + a[r].first < sum) l++;
            else r--;
        }
    }
    
    cout << "IMPOSSIBLE" << endl;
    
    return 0;
}
