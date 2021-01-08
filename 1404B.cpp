#include <bits/stdc++.h>
#define pb push_back
#define rep(i, a, n) for(int i = a; i <= n; i++)
#define REP(i, a, n) for(int i = a; i < n; i++)
using namespace std;

int T, n, a, b, da, db, u, v;

void solve() {
	cin >> n >> a >> b >> da >> db;
	a--, b--;
	
	vector<int> nodes[n], h(n, -1), h2(n, -1);

	REP(i, 1, n) {
		cin >> u >> v;
		u--, v--;
		nodes[u].pb(v);
		nodes[v].pb(u);
	}
	
	queue<int> q;
	
	q.push(a);
	h[a] = 0;
	int f;
	while (!q.empty()) {
		f = q.front();
		for (auto x : nodes[f]) {
			if (h[x] == -1) {
				q.push(x);
				h[x] = 1 + h[f];
			}
		}
		q.pop();
	}
	
	int dis = h[b];
	h = h2;
	
	q.push(f);
	h[f] = 0;
	while (!q.empty()) {
		f = q.front();
		for (auto x : nodes[f]) {
			if (h[x] == -1) {
				q.push(x);
				h[x] = 1 + h[f];
			}
		}
		q.pop();
	}
	
	cout << (min(h[f], db) > 2 * da && dis > da ? "Bob" : "Alice");
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		solve();
		cout << '\n';
	}
}
