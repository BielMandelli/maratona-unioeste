#include <bits/stdc++.h>
#define int long long
using namespace std;
 
signed main(){
    int t;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;

        vector<int> a;
        vector<int> b;
        vector<vector<int>> ab(n, vector<int>(m));
        bool invert = false;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cin >> ab[i][j];
                if(invert){
                    if(j%2) b.push_back(ab[i][j]);
                    else a.push_back(ab[i][j]);
                }
                if(!invert){
                    if(j%2) a.push_back(ab[i][j]);
                    else b.push_back(ab[i][j]);
                }
            }

            invert = !invert;
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int mv = 0;
        int medA = ((n*m)%2) ? ((n*m)/2) + 1 : (n*m)/2;
        int medB = (n*m)/2;

        int bestColor;
        for (int i = 0; i < medA-1; i++){
            if(binary_search(a.begin(), a.end(), a[i]) && binary_search(b.begin(), b.end(), a[i])) bestColor = a[i];
        }
        
        for (int i = 0; i < medA-1; i++){
            if(a[i] == bestColor) continue;
            if(a[i] == a[i+1]) {
                if(i+1 == medA-1) mv++;
                continue;
            }
            else mv++;
        }

        for (int i = 0; i < medB-1; i++){
            if(a[i] == bestColor) continue;
            if(b[i] == b[i+1]) {
                if(i+1 == medB-1) mv++;
                continue;
            }
            else mv++;
        }

        cout << mv << endl;

    }

    return 0;
}