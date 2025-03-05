#include <bits/stdc++.h>
#define int long long
using namespace std;
 
signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<vector<int>> m1(n, vector<int> (n)), m2(n, vector<int> (n));

    string s;
    for (int i = 0; i < n; i++){
        cin >> s;
        for (int j = 0; j < n; j++) {
            m1[i][j] = s[j] - '0';
        }
    }

    bool status = 0;
    int liv = 0;
    while (q--)
    {   
        if(!status){
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++) {
                    liv = 0;
                    if(i+1 < n) liv += (m1[i+1][j]) ? 1 : 0;
                    if(j+1 < n) liv += (m1[i][j+1]) ? 1 : 0;
                    if(i-1 >= 0) liv += (m1[i-1][j]) ? 1 : 0;
                    if(j-1 >= 0) liv += (m1[i][j-1]) ? 1 : 0;
                    if(i+1 < n && j+1 < n) liv += (m1[i+1][j+1]) ? 1 : 0;
                    if(i+1 < n && j-1 >= 0) liv += (m1[i+1][j-1]) ? 1 : 0;
                    if(i-1 >= 0 && j+1 < n) liv += (m1[i-1][j+1]) ? 1 : 0;
                    if(i-1 >= 0 && j-1 >= 0) liv += (m1[i-1][j-1]) ? 1 : 0;

                    if(m1[i][j]){
                        if(liv == 2 or liv == 3) m2[i][j] = 1;
                        else m2[i][j] = 0;
                    } else {
                        if(liv == 3) m2[i][j] = 1;
                        else m2[i][j] = 0;
                    }
                }
            }

            status = !status;
        }
        else {
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++) {
                    liv = 0;
                    if(i+1 < n) liv += (m2[i+1][j]) ? 1 : 0;
                    if(j+1 < n) liv += (m2[i][j+1]) ? 1 : 0;
                    if(i-1 >= 0) liv += (m2[i-1][j]) ? 1 : 0;
                    if(j-1 >= 0) liv += (m2[i][j-1]) ? 1 : 0;
                    if(i+1 < n && j+1 < n) liv += (m2[i+1][j+1]) ? 1 : 0;
                    if(i+1 < n && j-1 >= 0) liv += (m2[i+1][j-1]) ? 1 : 0;
                    if(i-1 >= 0 && j+1 < n) liv += (m2[i-1][j+1]) ? 1 : 0;
                    if(i-1 >= 0 && j-1 >= 0) liv += (m2[i-1][j-1]) ? 1 : 0;

                    if(m2[i][j]){
                        if(liv == 2 or liv == 3) m1[i][j] = 1;
                        else m1[i][j] = 0;
                    } else {
                        if(liv == 3) m1[i][j] = 1;
                        else m1[i][j] = 0;
                    }
                }
            }
            
            status = !status;
        }

        if(status) {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++) m1[i][j] = m2[i][j];
        } else {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++) m2[i][j] = m1[i][j];
        }
    }
    
    if(status){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++) cout << m1[i][j];
            cout << endl;
        }   
    } else {
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++) cout << m2[i][j];
            cout << endl;
        }
    }

    return 0;
}