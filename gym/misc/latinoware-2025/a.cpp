#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) ((int) (a).size())
#define ld long double

void dbg_out(string s) {  cerr << endl; }
template<typename H, typename...T>
void dbg_out(string s, H h, T... t){
    do {cerr << s[0]; s = s.substr(1);
    } while (sz(s) && s[0] != ',');
    cerr << " = " << h;
    dbg_out(s, t...);
}

#ifdef DEBUG
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

void solution(){
    string s;
    getline(cin, s);
    cout << "Qual o nome da sua equipe?" << endl;
    cout << "Nos chamamos " << s << "." << endl;
    cout << "Me perdoe, poderia repetir qual o nome da sua equipe?" << endl;
    cout << "Somos a equipe " << s << "." << endl;
    cout << "Me desculpe novamente. Poderia repetir mais uma vez, por favor?" << endl;
    cout << "SOMOS A EQUIPE " << s << "!!!" << endl;
    cout << "Ah, agora entendi. Boa prova!" << endl;
}

signed main(){
    // fastio;
    int cases = 1;
    // cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        solution();
    }
}