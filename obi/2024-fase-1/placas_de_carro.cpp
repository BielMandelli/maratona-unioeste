#include <bits/stdc++.h>
#define int long long
using namespace std;
 
signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(0);

    string s;
    cin >> s;

    if(s.size() > 8 or s.size() < 7) {
        cout << 0 << endl;
        return 0;
    }

    int valid;
    for (int i = 0; i < s.size(); i++)
    {
        if(s.size() == 8){
            if(i < 3) valid = (isalpha(s[i]) && isupper(s[i])) ? 1 : 0;
            else if (i == 3) valid = (s[i] == '-') ? 1 : 0;
            else if (i > 3) valid = (isdigit(s[i])) ? 1 : 0;
        } else {
            if(i < 3) valid = (isalpha(s[i]) && isupper(s[i])) ? 2 : 0;
            else if (i == 3) valid = (isdigit(s[i])) ? 2 : 0;
            else if (i == 4) valid = (isalpha(s[i]) && isupper(s[i])) ? 2 : 0;
            else if (i > 4) valid = (isdigit(s[i])) ? 2 : 0;
        }

        if(valid == 0) break;
    }

    cout << valid << endl;

    return 0;
}