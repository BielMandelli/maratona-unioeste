#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
vector<vector<int>> mat;
vector<vector<int>> matc;
int n,m;

bool valid(vector<vector<int>> copy){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(i+1 < n && copy[i][j] == copy[i+1][j]) return false;
            if(j+1 < m && copy[i][j] == copy[i][j+1]) return false;
            if(i-1 >= 0 && copy[i][j] == copy[i-1][j]) return false;
            if(j-1 >= 0 && copy[i][j] == copy[i][j-1]) return false;
        }
    }

    mat = copy;
    return true;
}

vector<vector<int>> fill(bool pair, vector<vector<int>> copy){
    bool start = pair%2;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(start%2) copy[i][j] = (copy[i][j]%2) ? copy[i][j] : copy[i][j]+1;
            else copy[i][j] = (copy[i][j]%2) ? copy[i][j]+1 : copy[i][j];

            start = !start;
        }
        if(!(m%2)) start = !start;
    }

    return copy;
}

signed main() {
    fastio;
    cin >> n >> m;
    mat.resize(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    for (int i = 0; i < 2; i++) {
        matc = fill(i, mat);

        if(valid(matc)) break;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}