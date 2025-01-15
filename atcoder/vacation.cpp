#include <bits/stdc++.h>
#define int long long
using namespace std;
bool isA, isB, isC;
int a,b,c;

void check(char blocked){
    if(blocked == 'a') {
        isA = true;
        isB = false;
        isC = false;
    } else if (blocked == 'b'){
        isA = false;
        isB = true;
        isC = false;
    } else if (blocked == 'c') {
        isA = false;
        isB = false;
        isC = true;
    }
    else (a >= b && b >= c) ? isA = true : (b >= c && b > a) ? isB = true : isC = true;
}

signed main(){
    int n;
    cin >> n;

    vector<vector<int>> d(n+1, vector<int>(3));

    for (int i = 1; i <= n; i++)
    {
        cin >> d[i][0];
        cin >> d[i][1];
        cin >> d[i][2];
    }

    vector<vector<int>> dp(n+1, vector<int>(3));

    dp[1][0] = d[1][0];
    dp[1][1] = d[1][1];
    dp[1][2] = d[1][2];

    for(int i=2;i<=n;i++)
    {
        dp[i][0] = d[i][0] + max(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = d[i][1] + max(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = d[i][2] + max(dp[i-1][0], dp[i-1][1]);
    }

    cout<< max(dp[n][0], max(dp[n][1], dp[n][2])) <<endl;
    

    return 0;
}