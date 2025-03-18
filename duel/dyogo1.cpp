#include <bits/stdc++.h>
using namespace std;
#define int long long

bool isVowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}
 
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> p(n);
    vector<string> ps(n);
    for (auto &x : p) cin >> x;
    cin.ignore(); 
    for (auto &x : ps) getline(cin, x);

    vector<int> vog;
    int ans = 0, valid = 1;
    for (int i = 0; i < n; i++)
    {
        ans = 0;
        for (int j = 0, k = 0; j < ps[i].size(); j++)
        {
            if(isVowel(ps[i][j])) {
                vog.push_back(j);
            }
        }

        if(vog.size() != p[i]) valid = 0;
        vog.clear();
    }
    
    if(valid) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}