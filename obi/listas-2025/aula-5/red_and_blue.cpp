#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> red(n);
        for (int i = 0; i < n; i++){
            cin >> red[i];
        }

        int m;
        cin >> m;
        vector<int> blue(m);
        for (int i = 0; i < m; i++){
            cin >> blue[i];
        }

        int mxb = 0, mxr = 0, sum = 0;
        for (int i = 0; i < n; i++){
            sum += red[i];
            mxr = max(sum, mxr);
        }

        sum = 0;
        for (int i = 0; i < m; i++){
            sum += blue[i];
            mxb = max(sum, mxb);
        }
        
        cout << max({0, mxr+mxb, mxr, mxb}) << endl;
    }   

    return 0;
}