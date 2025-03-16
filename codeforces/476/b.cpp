#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
#define int long long
const int MOD = 1e9+7;

signed main(){
    fastio;

    string s, s2;
    cin >> s >> s2;
    int mark = 0, ansPos = 0, lastPos = 0;

    double ans = 0;
    cout << setprecision(12) << fixed;

    for (int i = 0; i < s.size(); i++)
    {
        if(s[i] == '+') ansPos++;
        else ansPos--;

        if(s2[i] == '+') lastPos++;
        else if(s2[i] == '-') lastPos--;
        else mark++;
    }

    int dist = ansPos - lastPos;
    double totalP = pow(2,mark);
    if((dist+mark) % 2 != 0 or mark < abs(dist)) ans = 0;
    else{
        int moves = (mark+abs(dist))/2;
        double cnt = 1;
        for (int i = 0; i < moves; i++) cnt *= mark-i;
        for (int i = 2; i <= moves; i++) cnt /= i;
        
        ans = cnt/totalP;
    }

    cout << ans << endl;
    
    return 0;
}