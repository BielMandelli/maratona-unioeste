#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    double n;

    cin >> n;

    int cem = 0, cinq = 0, vinte = 0, dez = 0, cinco = 0, dois = 0, um = 0;
    int cinqMoeda = 0, vinteMoeda = 0, dezMoeda = 0, cincoMoeda = 0, umMoeda = 0;

    cem = n/100;
    n -= cem*100;

    cinq = n/50;
    n -= cinq*50;

    vinte = n/20;
    n -= vinte*20;

    dez = n/10;
    n -= dez*10;

    cinco = n/5;
    n -= cinco*5;

    dois = n/2;
    n -= dois*2;

    um = n/1;
    n -= um*1;

    cinqMoeda = n/0.5;
    n -= cinqMoeda*0.5;

    vinteMoeda = n/0.25;
    n -= vinteMoeda*0.25;

    dezMoeda = n/0.10;
    n -= dezMoeda*0.10;

    cincoMoeda = n/0.05;
    n -= cincoMoeda*0.05;

    umMoeda = n/0.01;
    n -= umMoeda*0.01;

    cout << "NOTAS:" << endl << cem << " nota(s) de R$ 100.00" << endl << cinq << " nota(s) de R$ 50.00" << endl << vinte << " nota(s) de R$ 20.00" << endl;
    cout << dez << " nota(s) de R$ 10.00" << endl << cinco << " nota(s) de R$ 5.00" << endl << dois << " nota(s) de R$ 2.00" << endl;
    cout << "MOEDAS:" << endl << um << " moeda(s) de R$ 1.00" << endl << cinqMoeda << " moeda(s) de R$ 0.50" << endl << vinteMoeda << " moeda(s) de R$ 0.25" << endl;
    cout << dezMoeda << " moeda(s) de R$ 0.10" << endl << cincoMoeda << " moeda(s) de R$ 0.05" << endl << umMoeda << " moeda(s) de R$ 0.01" << endl;
    return 0;
}
