#include <bits/stdc++.h>
#define PB push_back
using namespace std;

int n, s, mi, ma, q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	int v[n];
	set<int> set;
	v[0] = 0;
	set.insert(0);
	
	for (int i = 0; i < n - 1; i++) {
		cin >> q;
		v[i + 1] = v[i] + q;
		set.insert(v[i + 1]);
		mi = min(mi, v[i + 1]);
		ma = max(ma, v[i + 1]);
	}

	if ((int)set.size() < n || ma - mi != n - 1) 
	    cout << -1;
	else 
		for (auto x : v)
			cout << x - mi + 1 << " ";
}
