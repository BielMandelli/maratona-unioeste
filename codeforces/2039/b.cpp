#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main (){
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        bool valid = false;

        for (int i = 0; i < s.size(); i++){
            if(i+1 >= s.size()) break;
            if(s[i] == s[i+1]){
                cout << s[i] << s[i+1] << endl;
                valid = true;
                break;
            }
        }

        if(valid) continue;

        for (int i = 0; i < s.size(); i++){
            if(i+1 >= s.size() || i+2 >= s.size()) break;
            if(s[i] != s[i+1] && s[i+1] != s[i+2] && s[i+2] != s[i]){
                cout << s[i] << s[i+1] << s[i+2] << endl;
                valid = true;
                break;
            }
        }

        if(valid) continue;

        cout << "-1" << endl;
    }
    

    return 0;
}