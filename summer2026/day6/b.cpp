#include <bits/stdc++.h>
using namespace std;

#define int long long

bool ispalindrome(string s){
    for (int i = 0, j = s.size()-1; i < j; i++,j--)
    {
        if(s[i] != s[j]) return false;
    }
    return true;
}

void solve(){
    string s;
    cin >> s;

    if(ispalindrome(s)) cout << s << endl;
    else {
        string rev = s;

        bool valid = false;
        string cur = "", temp;
        for (int i = 0; i < rev.size(); i++)
        {
            if(valid) break;
            cur = temp + rev[i];
            temp = cur;
            reverse(cur.begin(), cur.end());
            if(ispalindrome(s+cur)) valid = true;
        }
        
        cout << s + cur << endl;
    }
}

signed main(){
    int cases = 1;
    // cin >> cases;
    for (int i = 0; i<cases;i++) solve();
}