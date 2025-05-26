#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long

signed main()
{
    bieo;
    
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<vector<int>> matriz(n, vector<int>(n));
        vector<int> p(2*n, 0);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++){
                cin >> matriz[i][j];
                p[(i+j+1)] = matriz[i][j];
            }
                
        int sum = accumulate(p.begin(), p.end(), 0);
        int totalSum = ((2*n)*((2*n)+1))/2; //Fórmula para pegar a soma de 1 até 2*n

        int weirdNum = totalSum - sum;

        for(auto x : p){
            if(x == 0) cout << weirdNum << " ";
            else cout << x << " ";
        }
        cout << endl;
    }
    
    return 0;
}