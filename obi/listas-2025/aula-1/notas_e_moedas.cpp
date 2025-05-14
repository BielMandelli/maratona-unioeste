#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    double input;
    cin >> input;

    int n = (int)(input * 100);

    int cem = n / 10000;     n %= 10000;
    int cinq = n / 5000;     n %= 5000;
    int vinte = n / 2000;    n %= 2000;
    int dez = n / 1000;      n %= 1000;
    int cinco = n / 500;     n %= 500;
    int dois = n / 200;      n %= 200;

    int um = n / 100;        n %= 100;
    int cinqMoeda = n / 50;  n %= 50;
    int vinteMoeda = n / 25; n %= 25;
    int dezMoeda = n / 10;   n %= 10;
    int cincoMoeda = n / 5;  n %= 5;
    int umMoeda = n / 1;     n %= 1;

    cout << "NOTAS:" << endl;
    cout << cem << " nota(s) de R$ 100.00" << endl;
    cout << cinq << " nota(s) de R$ 50.00" << endl;
    cout << vinte << " nota(s) de R$ 20.00" << endl;
    cout << dez << " nota(s) de R$ 10.00" << endl;
    cout << cinco << " nota(s) de R$ 5.00" << endl;
    cout << dois << " nota(s) de R$ 2.00" << endl;

    cout << "MOEDAS:" << endl;
    cout << um << " moeda(s) de R$ 1.00" << endl;
    cout << cinqMoeda << " moeda(s) de R$ 0.50" << endl;
    cout << vinteMoeda << " moeda(s) de R$ 0.25" << endl;
    cout << dezMoeda << " moeda(s) de R$ 0.10" << endl;
    cout << cincoMoeda << " moeda(s) de R$ 0.05" << endl;
    cout << umMoeda << " moeda(s) de R$ 0.01" << endl;

    return 0;
}
