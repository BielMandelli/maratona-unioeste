#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        string s;
        cin >> n >> s;

        bool side = true;

        vector<int> p1, p2, p3;

        for (int i = 0; i < n; i++)
        {
            if(s[i] == '_') p1.push_back(i);
            if(s[i] == '(') p2.push_back(i);
            if(s[i] == ')') p3.push_back(i);
        }

        int ans = 0;
        
        for (int i = 0; i < n; i++)
        {
            if (p2.empty() && p3.empty());
            if (p1.empty()) break;

            if (s[i] == '_' && !p2.empty() && p2[0] < p1[0]) {

                ans += p1[0] - p2[0];
                p2.erase(p2.begin());
                p1.erase(p1.begin());
            }

            
            else if(s[i] == '_') {
                ans += p3[0] - p1[0];
                p3.erase(p3.begin());
                p1.erase(p1.begin());
            } 
            

        }

        cout << ans << endl;
        
    }

    return 0;
}