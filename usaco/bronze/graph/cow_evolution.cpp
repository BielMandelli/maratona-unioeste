#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long

signed main() {
    bieo;

    int n;
    cin >> n;

    map<string, set<int>> featureMap;

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            string feature;
            cin >> feature;
            featureMap[feature].insert(i);
        }
    }

    bool valid = true;
    vector<string> features;
    for (auto& [feature, _] : featureMap) features.push_back(feature);

    for (int i = 0; i < features.size(); i++) {
        for (int j = i + 1; j < features.size(); j++) {
            auto& setA = featureMap[features[i]];
            auto& setB = featureMap[features[j]];

            set<int> intersection;
            set_intersection(setA.begin(), setA.end(), setB.begin(), setB.end(), inserter(intersection, intersection.begin()));

            if (!intersection.empty() && setA != setB) {
                if (!includes(setA.begin(), setA.end(), setB.begin(), setB.end()) && !includes(setB.begin(), setB.end(), setA.begin(), setA.end())) {
                    valid = false;
                    break;
                }
            }
        }
        if (!valid) break;
    }

    if(valid) cout << "yes";
    else cout << "no";
    cout << endl;

    return 0;
}
