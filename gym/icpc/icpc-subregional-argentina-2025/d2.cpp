#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) (int) (a).size()
#define ll long long
#define ld long double

void dbg_out(string s) { cerr << endl; }
template<typename H, typename... T>
void dbg_out(string s, H h, T... t){
    do { cerr << s[0]; s = s.substr(1);
    } while (sz(s) && s[0] != ',');
    cerr << " = " << h;
    dbg_out(s, t...);
}

#ifdef DEBUG
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS___)
#else
#define dbg(...) 42
#endif

struct Round {
    long long vL; string sL; 
    long long vF; string sF; 
};

void solve(){
     int M, N;
    cin >> M >> N;
    int R = M + N;

    vector<Round> rounds(R);
    vector<string> allSuits;
    for (int i = 0; i < R; i++) {
        cin >> rounds[i].vL >> rounds[i].sL >> rounds[i].vF >> rounds[i].sF;
        allSuits.push_back(rounds[i].sL);
        allSuits.push_back(rounds[i].sF);
    }

    // conjunto de naipes distintos
    sort(allSuits.begin(), allSuits.end());
    allSuits.erase(unique(allSuits.begin(), allSuits.end()), allSuits.end());

    // para cada naipe vamos armazenar "último vencedor certo"
    unordered_map<string,int> lastWinner; // 0 = Lautaro, 1 = Fiorella, -1 = indefinido
    for (auto &s : allSuits) lastWinner[s] = -1;

    int wL = 0, wF = 0;
    int first = 0; // Lautaro começa

    for (int i = 0; i < R; i++) {
        auto [vL, sL, vF, sF] = rounds[i];
        int winner = -1;

        if (sL == sF) {
            // mesmo naipe → determinado
            winner = (vL > vF ? 0 : 1);
        } else {
            // diferentes
            // se algum for trunfo → só fixa para aquele naipe
            lastWinner[sL] = 0;
            lastWinner[sF] = 1;
            // se nenhum for trunfo → depende de first
            winner = first;
        }

        if (winner == 0) wL++;
        else wF++;
        first = winner;
    }

    string ans = "*";
    if (wL == M && wF == N) {
        // qualquer naipe que apareceu pode ser trunfo
        ans = allSuits[0];
    }
    cout << ans << "\n";
}

signed main(){
    fastio;
    int t=1;
    //cin >> t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }
    return 0;
}