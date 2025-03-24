#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
#define int long long
const int MOD = 1e9 + 7;

signed main()
{
    fastio;
    int n;
    cin >> n;
    unordered_map<string, int> milk = {
        {"Bessie", 0}, {"Elsie", 0}, {"Daisy", 0}, {"Gertie", 0},
        {"Annabelle", 0}, {"Maggie", 0}, {"Henrietta", 0}
    };
    string s;
    int aux;
    for (int i = 0; i < n; i++)
    {
        cin >> s >> aux;
        milk[s] += aux;
    }

    vector<pair<string, int>> milkSort(milk.begin(), milk.end());

    sort(milkSort.begin(), milkSort.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.second < b.second; 
    });

    bool first = true;
    for (int i = 0; i < milkSort.size(); i++)
    {
        if(first && i+1 < milkSort.size() && milkSort[i].second == milkSort[i+1].second) {
            continue;
        }
        else {
            if(!first && i+1 < milkSort.size() && milkSort[i].second == milkSort[i+1].second) {
                cout << endl << "Tie" << endl;
                break;
            } else if(!first) {
                cout << endl << milkSort[i].first << endl;
                break;
            }

            first = false;
        }

        if(i+1 == milkSort.size()) cout << endl << "Tie" << endl;
    }
    
    
    
    return 0;
}