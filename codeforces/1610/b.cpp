#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

bool check(vector<int> palind){
    for (int i = 0, j = palind.size()-1; i < j; i++, j--) if(palind[i] != palind[j]) return false;

    return true;
}

signed main() {
    // bieo;
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for(auto &x : a) cin >> x;

        int ieq = -1, jeq = -1;

        for (int i = 0, j = n-1; i < j; i++, j--)
        {
            // cout << "a " << a[i] << " a " << a[j] << endl;
            
            if(a[i] != a[j]) {
                ieq = a[i];
                jeq = a[j];
                break;
            }
        }
        
        if(!ieq && !jeq) {
            cout << "YES" << endl;
            continue;
        }

        vector<int> op1, op2;
        for (int i = 0; i < n; i++) if(a[i] != ieq) op1.push_back(a[i]);
        for (int i = 0; i < n; i++) if(a[i] != jeq) op2.push_back(a[i]);

        // for (int i = 0; i < op2.size(); i++) cout << op2[i] << endl;
        
        cout << ((check(op1) or check(op2)) ? "YES" : "NO") << endl;
    }
        
    
    return 0;
}
