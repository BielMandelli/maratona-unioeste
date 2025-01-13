#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n,a,b,impar = 0;
    cin >> n;

    vector<int> maracas(n+1);
    vector<int> dist;

    for (int i = 1; i <= n; i++)
    {
        cin >> maracas[i];
        if(maracas[i]%2){
            dist.push_back(i);
            impar++;
        }
    }
    
    cin >> a >> b;

    if(impar%2) {
        cout << "-1" << endl;
        return 0;
    }

    int secs = 0, m = dist.size(), d, d2, ans = 0;

    for (int i = 0; i < m; i += 2) {
        d = abs(dist[i] - dist[i + 1]); 
        secs += d * min(a,b);
    }

    for (int i = 0; i < m; i+= 2)
    {
        if(i == m-1) break;
        if(i == 0) {
                d2 = abs(dist[m-1] - n - dist[i]);
                i = -1;
                ans += d2 * min(a,b);
                continue;
        } 

        d2 = abs(dist[i] - dist[i + 1]);
        ans += d2 * min(a,b);
    }

    cout << min(ans,secs) << endl;

    return 0;
}