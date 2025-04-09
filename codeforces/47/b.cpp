#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
int a = 0,b = 0,c = 0;

void check(string s){
    if(s[0] == 'A'){
        if(s[1] == '>'){
            if(s[2] == 'B'){
                a++;
                b--;
            }
            else {
                a++;
                c--;
            }
        } else {
            if(s[2] == 'B'){
                a--;
                b++;
            }
            else {
                a--;
                c++;
            }
        }
    }

    else if(s[0] == 'B'){
        if(s[1] == '>'){
            if(s[2] == 'A'){
                a--;
                b++;
            }
            else {
                b++;
                c--;
            }
        } else {
            if(s[2] == 'A'){
                a++;
                b--;
            }
            else {
                b--;
                c++;
            }
        }
    }

    else {
        if(s[1] == '>'){
            if(s[2] == 'B'){
                c++;
                b--;
            }
            else {
                c++;
                a--;
            }
        } else {
            if(s[2] == 'B'){
                c--;
                b++;
            }
            else {
                a++;
                c--;
            }
        }
    }
}
 
signed main()
{
    bieo;
    string w1,w2,w3;
    cin >> w1 >> w2 >> w3;

    check(w1);
    check(w2);
    check(w3);
    
    // cout << a << " " << b << " " << c << endl;
    if(a != b && b != c){
        if(a < c && a < b && b < c) cout << "ABC";
        else if(a < c && a < b && b > c) cout << "ACB";
        else if(a < c && a > b) cout << "BAC";
        else if(a > c && a < b) cout << "CAB";
        else if(a > c && a > b && b < c) cout << "BCA";
        else cout << "CBA";
    } else cout << "Impossible";

    cout << endl;
}