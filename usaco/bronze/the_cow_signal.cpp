#include <bits/stdc++.h>
using namespace std;
#define int long long
 
signed main(){
    int n,m,k;

    cin >> n >> m >> k;
    vector<string> orig(n);
    vector<string> sign;

    for (auto &a : orig) cin >> a;
    
    for (int i = 0, last = 0; i < n; i++)
    {
        string newString, s = orig[i];
        for (int j = 0; j < m; j++)
        {
            char c = s[j];
            newString += string(k, c);
        }

        for (int j = 0; j < k; j++) sign.push_back(newString);
    }

    for (int i = 0; i < n*k; i++)
    {
        cout << sign[i];
        cout << endl;
    }
    
    

    return 0;
}