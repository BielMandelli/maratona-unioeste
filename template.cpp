#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long

signed main()
{
    bieo;
    
    int n;
    vector<int> vetor(n);

    for (int i = 0; i < n; i++)
    {
        cin >> vetor[i];
    }
    
    sort(vetor.begin(), vetor.end());

    int valor = 1;
    int posicao = upper_bound(vetor.begin(), vetor.end(), valor) - vetor.begin();
    
    return 0;
}