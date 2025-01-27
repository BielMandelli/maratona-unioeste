#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int t;
    cin >> t;

    while (t--)
    {
        int firstP,m,n;
        set<int> dp[2];

        cin >> n >> m >> firstP;

        int act = 0;

        dp[act].insert(firstP);

        while (m--){
            int x; 
            char ch;    
            cin >> x >> ch;
            while (!dp[act].empty())
            {
                int old = *(dp[act].begin());
                dp[act].erase(old);
                if(ch == '?' or ch == '0') dp[act ^ 1].insert((old + x - 1) % n + 1);
                if (ch == '?' or ch == '1') dp[act ^ 1].insert((old - x - 1 + n) % n + 1);
            }
            act ^= 1;
        }

        cout << dp[act].size() << endl;
        for (auto& d : dp[act])
        {
            cout << d << " ";
        }

        cout << endl;
    }

    return 0;
}
