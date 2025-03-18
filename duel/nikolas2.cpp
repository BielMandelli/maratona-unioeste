#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
#define int long long
const int MOD = 1e9+7;

bool isMirror(char c){
    if(c == 'A' or c == 'H' or c == 'I' 
        or c == 'M' or c == 'O' or c == 'T' 
        or c == 'U' or c == 'U' or c == 'W' 
        or c == 'V' or c == 'X' or c == 'Y') return true;
    else return false;
}

signed main(){
    fastio;
    string s, sr;
    cin >> s; 

    sr = s;
    reverse(sr.begin(), sr.end());

    for (int i = 0; i < s.size(); i++)
    {
        if(s[i] != sr[i] or !isMirror(s[i])) {
            cout << "NO" << endl;
            return 0;
        }
    }
    
    cout << "YES" << endl;
    return 0;
}