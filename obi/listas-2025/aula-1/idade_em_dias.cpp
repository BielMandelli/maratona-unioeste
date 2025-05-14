#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n;
    cin >> n;

    int ano, mes, dia;
    ano = n/365; n%=365;
    mes = n/30; n%=30;
    dia = n;
        
    cout << ano << " ano(s)" << endl;
    cout << mes << " mes(es)" << endl;
    cout << dia << " dia(s)" << endl;
    
    return 0;
}
