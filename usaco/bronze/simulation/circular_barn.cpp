#include <bits/stdc++.h>
using namespace std;
#define int long long
 
signed main(){
    int n, best, ans = INT32_MAX;
    cin >> n;
    vector<int> cows(n);

    for (auto &x : cows) cin >> x;

    int worst = 0, bestWorst = INT32_MAX, dist, sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = 0; j < n; j++)
        {
            if(j < i) dist = abs(i - n - j);
            else dist = abs(i - j);

            sum += cows[j]*dist;
        }
        ans = min(ans, sum);
    }

    cout << ans << endl;

    return 0;
}