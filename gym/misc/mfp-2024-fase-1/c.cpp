#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
vector<int> s;
int ans = -1, n;

void solve(int k, int c){
    if(k >= (1<<n)){
        ans = max(ans, c);
        return;
    }
    
    solve(k*2, c+s[k-1]);
    solve(k*2+1, c+s[k-1]);
}

signed main() {
    bieo;
    cin >> n;
    
    for (int i = 0; i < (1<<n)-1; i++)
    {
        int aux;
        cin >> aux;
        s.push_back(aux);
    }
    
    solve(1, 0);

    cout << ans << endl;
        
    return 0;
}
