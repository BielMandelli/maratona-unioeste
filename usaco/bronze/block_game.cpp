#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int n;
    cin >> n;
    vector<int> alph(26, 0);
    vector<int> alph2(26, 0);
    vector<int> ans(26, 0);

    for (int i = 0; i < n; i++)
    {
        string s, s2;
        cin >> s >> s2;
        for (int i = 0; i < s.size(); i++)
        {
            int value = (s[i] - '0') - 49;
            alph[value]++;
        }

        for (int i = 0; i < s2.size(); i++)
        {
            int value = (s2[i] - '0') - 49;
            alph2[value]++;
        }

        for (int i = 0; i < 26; i++)
        {
            ans[i] += max(alph[i], alph2[i]);
            alph[i] = 0;
            alph2[i] = 0;
        }
    }
    
    for (int i = 0; i < 26; i++)
    {
        cout << ans[i] << endl;
    }
    
    

    return 0;
}