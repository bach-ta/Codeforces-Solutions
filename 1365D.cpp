#include <bits/stdc++.h>
#define Y "Yes"
#define N "No"
#define REP(i, a, n) for(int i = a; i < n; i++)
#define fi first
#define se second
#define pi pair<int, int>
#define pb push_back
using namespace std;

int T, n, m, dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
char c[50][50];
bool p[50][50];

bool irx(int x) {
	return (x >= 0 && x < n);
}

bool iry(int x) {
	return (x >= 0 && x < m);
}

void bfs() {
	memset(p, 0, sizeof(p));
	p[n-1][m-1] = 1;
	queue<pi> q;
	if (n-1 > 0 && c[n-2][m-1] != '#') q.push({n-2, m-1}), p[n-2][m-1] = 1;
	if (m-1 > 0 && c[n-1][m-2] != '#') q.push({n-1, m-2}), p[n-1][m-2] = 1;
	while (!q.empty()) {
		pi f = q.front();
		REP(i, 0, 4) {
			int x = f.fi + dx[i], y = f.se + dy[i];
			if (irx(x) && iry(y) && c[x][y] != '#' && p[x][y] == 0) q.push({x, y}), p[x][y] = 1;
		}
		q.pop();
	}
}

void solve() {
	cin >> n >> m;
	vector<pi> b, g;
	REP(i, 0, n) {
		REP(j, 0, m) {
			cin >> c[i][j];
			if (c[i][j] == 'B') b.pb({i, j});
			else if (c[i][j] == 'G') g.pb({i, j});
		}
	}
	if (g.empty()) cout << Y;
	else {
		bool ans = 1;
		for (auto x : b) {
			REP(i, 0, 4) {
				int u = x.fi + dx[i], v = x.se + dy[i];
				if (irx(u) && iry(v) && c[u][v] == '.') c[u][v] = '#';
			}
		}
		
		if (c[n-1][m-1] == '#') cout << N;
		else {
			
			bfs();
			
			for (auto x : g) {
				if (!p[x.fi][x.se]) {
					ans = 0;
					break;
				}
			}
			for (auto x : b) {
				if (p[x.fi][x.se]) {
					ans = 0;
					break;
				}
			}
			if (ans) cout << Y;
			else cout << N;
		} 
	}
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
