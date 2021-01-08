#include <bits/stdc++.h>
#define ll long long
#define rep(i, a, n) for(int i = a; i <= n; i++)
using namespace std;

int T, n, m, c0[61], c1[61];

void solve() {
	cin >> n >> m;
	bool c[n+1][m+1];
	memset(c0, 0, sizeof(c0));
	memset(c1, 0, sizeof(c1));
	int ans = 0;
	
	rep(i, 1, n)
		rep(j, 1, m) {
			cin >> c[i][j];
			if (c[i][j]) c1[i+j-1]++;
			else c0[i+j-1]++;
		}
		
	rep(i, 1, (n + m - 1)/2)
		ans += min(c0[i] + c0[n+m-i], c1[i] + c1[n+m-i]);
	cout << ans;
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
