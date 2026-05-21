#include <bits/stdc++.h>
using namespace std;

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

typedef struct node{
    node *right = NULL, *left = NULL;
    int life, val;
    bool check;
}; 

int n;
void fill(node* &head, const vector<int>& a, const vector<int>& d){
    node *last = NULL;

    for(int i = 0; i < n; i++){
        node *cur = (node*) malloc(sizeof(node));
        cur->val = a[i];
        cur->life = d[i];
        cur->left = last;
        cur->right = NULL;
        cur->check = true;

        if(last) last->right = cur;
        else head = cur;

        last = cur;
    }
}

void remove(node* &head){
    node *cur = head;

    while(cur != NULL){
        if(cur->life == -1){
            node *l = cur->left;
            node *r = cur->right;

            if(l) l->right = r;
            if(r) r->left = l;

            if(cur == head) head = r;

            node *to_delete = cur;
            cur = r;

            free(to_delete);
        } else {
            cur = cur->right;
        }
    }
}

bool can = true;
int kill(node * &link){
    int k = 0;
    if(!can) return 0;

    node *cur = link;
    while(cur != NULL){
        if(!cur->check){
            cur = cur->right;
            continue;
        }

        int l = 0, r = 0;
        if(cur->left != NULL) l = cur->left->val;
        if(cur->right != NULL) r = cur->right->val;

        if(l == 0 && r == 0){
            can = false;
            return 0;
        }
        // cout << l << " " << r << endl;
        if(l+r > cur->life) {
            k++;
            cur->life = -1;

            if(cur->left) cur->left->check = true;
            if(cur->right) cur->right->check = true;
        } else cur->check = false;

        cur = cur->right;
    }

    // cout << "terminando passagem com k: " << k << endl;

    if(k == 0) can = false;
    return k;
}

void solution(){
    cin >> n;
    can = true;

    vector<int> a(n);
    vector<int> d(n);

    for(auto &x : a) cin >> x;
    for(auto &x : d) cin >> x;

    node * linkedlist = NULL;
    fill(linkedlist, a, d);
    
    // cout << "-------------" << endl;
    for (int i = 0; i < n; i++)
    {
        // kill(linkedlist);
        cout << kill(linkedlist) << ' ';
        if(can) remove(linkedlist);
    }
    cout << endl;
}

signed main(){
    fastio;
    int cases = 1;
    cin >> cases;
    for (int i = 0; i < cases; i++){
        solution();
    }
    
}
