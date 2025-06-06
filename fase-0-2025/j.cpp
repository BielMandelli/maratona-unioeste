#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

signed main() {
    bieo;
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n), y(n*2, 1e9);
    for(auto &x: a) cin >> x;

    for (int i = 0; i < n*2; i++) y[i] = a[i%n] - k*i; 

    stack<int> stk;

    for (int i = 0; i < n*2; i++)
    {
        while (!stk.empty() && y[i] < y[stk.top()])
        {
            int pos = stk.top();
            stk.pop();
            if(pos < n) b[pos] = i;
        }
        stk.push(i);
    }
    
    for (int i = 0; i < n; i++)
    {
        if(b[i] == 1e9) b[i] = i+n;
        cout << (b[i]%n)+1 << " ";
    }
    cout << endl;

    return 0;
}