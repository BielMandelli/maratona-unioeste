#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int peca1, peca2, n1, n2;
    double preco1, preco2;

    cin >> peca1 >> n1 >> preco1 >> peca2 >> n2 >> preco2;

    double valor1 = (double) n1*preco1;
    double valor2 = (double) n2*preco2;

    cout << setprecision(2) << fixed;
    cout << "VALOR A PAGAR: R$ " << valor1+valor2 << endl;

    return 0;
}
