#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
#define int long long
const int MOD = 1e9+7;

signed main(){
    fastio;
    int n, q;
    cin >> n >> q;
    vector<int> c(n), freq(51, 1e9);
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
        freq[c[i]] = min(freq[c[i]], i);
    }
    
    int search;
    while(q--){
        cin >> search;
        cout << freq[search] + 1 << " ";
        
        if(freq[search] != 0){
            for (int i = 0; i < 51; i++)
            {
                if(freq[i] < freq[search]) freq[i]++;
            }
        }
        
        freq[search] = 0;
    }
    cout << endl;

}