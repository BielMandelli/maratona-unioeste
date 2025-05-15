#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

    ll n, pontuacao = 0;
    string gabarito, resposta;

    cin >> n >> gabarito >> resposta;

    for (int i = 0; i < n; i++)
    {
        if(gabarito[i] == resposta[i]){
            pontuacao++;
        } 
    }
    
    cout << pontuacao << endl;

    return 0;
}