#include <bits/stdc++.h>
using namespace std;
#define int long long
 
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s, sub;
    cin >> s;

    int notA = 0, a = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i] == 'a') a++;
        else {
            notA++;
            sub += s[i];
        }  
    }
    
    bool valid = true;
    if(notA%2) valid = false;
    else for (int i = 0, j = notA/2; i < notA/2; i++, j++) if(sub[i] != sub[j]) valid = false;
    
    if(valid){
        for (int i = 0, j = s.size() - notA/2; i < notA/2; i++, j++)
            if(s[j] != sub[i]) valid = false;
    } 
    
    if(valid){
        s.erase(s.end() - notA/2, s.end());
        cout << s << endl;
    }
    else cout << ":(" << endl;

    return 0;
}