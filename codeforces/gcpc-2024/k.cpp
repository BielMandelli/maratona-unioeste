#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

string rotate(string s, char method){
    string news = "";
    
    if(method == 'h'){
        for (int i = s.size()-1; i >= 0; i--)
        {
            if(s[i] == 'q') news += 'p';
            if(s[i] == 'b') news += 'd';
            if(s[i] == 'd') news += 'b';
            if(s[i] == 'p') news += 'q';
        }
    } else if(method == 'v'){
        for (int i = 0; i < s.size(); i++)
        {
            if(s[i] == 'q') news += 'd';
            if(s[i] == 'b') news += 'p';
            if(s[i] == 'd') news += 'q';
            if(s[i] == 'p') news += 'b';
        }
    } else if(method == 'r'){
        for (int i = s.size()-1; i >= 0; i--)
        {
            if(s[i] == 'q') news += 'b';
            if(s[i] == 'b') news += 'q';
            if(s[i] == 'd') news += 'p';
            if(s[i] == 'p') news += 'd';
        }
    }

    return news;
}

signed main() {
    bieo;
    string s, t;
    cin >> s >> t;
    map<char, int> times;

    for (int i = 0; i < t.size(); i++) times[t[i]]++;
    
    if(times['h']%2) s = rotate(s, 'h');
    if(times['r']%2) s = rotate(s, 'r');
    if(times['v']%2) s = rotate(s, 'v');
    
    cout << s << endl;

    return 0;
}
