#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define minecraft cin.tie(0)->sync_with_stdio(0);
#define endl "\n"
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define ll long long 
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) ((int) (a).size())
#define ld long double

void dbg_out(string s) {cerr << endl;}
template<typename H, typename ...T>
void dbg_out(string s, H h, T... t){
    do{cerr << s[0]; s = s.substr(1);
    } while(sz(s) && s[0] != ',');
    cerr << " = " << h;
    dbg_out(s, t...);
}

#ifdef DEBUG
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

 
int main (){
 
    minecraft;

    ll t = 1;
    //cin>>n;
    while(t--){
        ll n;
        cin>>n;
        vector<vector<ll>> psum (2,vector<ll>(n+1));
        string s;
        cin>>s;


        for(ll i = 1; i <= n ; i++){
            char c = s[i-1];
            psum[0][i]+=psum[0][i-1]+(c=='A');
            psum[1][i]+=psum[1][i-1]+(c=='C');
        }


        bool seq = false;
        ll in,fim;
        vector<pair<ll,ll>> seqs;
        for(ll i = 0; i < n; i++){
            char c = s[i];

            if(seq && c == s[i-1]){
                seq = false;
                fim = i-1;
                if(in!=fim)seqs.push_back({in,fim});
            }

            if(c == 'A'){
                if(!seq){
                    in = i;
                    seq=true;
                }
            }
        }

         if(seq){
                seq = false;
                fim = n-1;
                if(in!=fim)seqs.push_back({in,fim});
            }

        // for(auto [x,y] : seqs) dbg(x,y);
        ll q;
        cin>>q;
        while(q--){
            ll l,r;
            cin>>l>>r;

            bool valid = false;

            //cout<<psum[0][r]<<" "<<psum[0][l-1]<<" "<<psum[1][r]<<" "<<psum[1][l-1]<<endl;
            dbg(q, psum[0][r], psum[0][l-1], psum[1][r], psum[1][l-1]);
            if(psum[0][r]-psum[0][l-1]==0 || psum[1][r]-psum[1][l-1]==0) cout<<"SIM"<<endl;

            else if(s[l-1]== 'C') cout<<"NAO"<<endl;

            else {
                auto it = lower_bound(seqs.begin(), seqs.end(), make_pair(l-1, r-1));
                if (it == seqs.end()) {
                    cout << "NAO" << endl;
                } else {
                    dbg(it->first);
                    if (it->first <= l-1 && r-1 <= it->second) cout << "SIM" << endl;
                    else cout << "NAO" << endl;
                }
            }
        }
        // for(auto [p,s] : seqs){
        //     cout<< p <<" "<<s<<endl;
        // }
        
        
    }
 
    return 0;
    
}