#include<bits/stdc++.h>

#define INF 100000000000000000
#define int long long
#define pb push_back
#define fori(i,n) for (int i = 0; i < n; i++)

using namespace std;

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n,q;
	cin >> n >> q;

	vector<int> arr(n);
	vector<int> pos(n);
	fori(i,n){
		cin >> arr[i];
		arr[i]--;

		pos[arr[i]] = i;
	}

	vector<pair<int,int>> bounds(n);
	int start = INF, end = -INF;
	fori(i,n){
		start = min(start, pos[i]);
		end = max(end, pos[i]);

		bounds[i] = {start, end};
	}

	fori(_,q){
		int l,r;
		cin >> l >> r;
		l--; r--;

		auto [st, en] = bounds[r-l];

		if (l <= st and r >= en){
			cout << "Bom\n";
		}
		else{
			cout << "Ruim\n";
		}
	}
}