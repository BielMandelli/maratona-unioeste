#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    double a,b;

    cin >> a >> b;

    double nota = (a+b)/2;

    if(nota > 7.0) cout << "Aprovado" << endl;
    else if (nota < 4.0) cout << "Reprovado" << endl;
    else cout << "Recuperacao" << endl;
    
    return 0;
}