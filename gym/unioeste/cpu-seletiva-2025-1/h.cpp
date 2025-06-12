#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    string s;
    cin >> n >> s;

    vector<int> seq;

    int aux = 1;
    for (int i = 0; i < n; i++)
    {
        if(i < n-1 && s[i] == s[i+1]) aux++;
        else {
            seq.push_back(aux);
            aux = 1;
        }
    }   

    int ans = 0;
    for (int i = 0; i < seq.size()-1; i++)
    {
        if(seq[i] == seq[i+1]) ans = max(ans, seq[i] + seq[i+1]);
        if(seq[i] < seq[i+1] or seq[i] > seq[i+1]) ans = max(ans, min(seq[i] , seq[i+1])*2);
        if(i+2 < seq.size())
            if(seq[i] + seq[i+2] == seq[i+1]) ans = max(ans, seq[i] + seq[i+1] + seq[i+2]);
            else if (seq[i] + seq[i+2] > seq[i+1]) ans = max(ans, min(seq[i] + seq[i+2], seq[i+1])*2);
    }
    
    cout << ans << endl;
    
    return 0;
}
