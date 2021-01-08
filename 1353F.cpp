#include <bits/stdc++.h>
#define ll long long
using namespace std;

int t, n, m;
ll a[101][101], ans;

void solve() {
	cin >> n >> m;
	ans = LLONG_MAX;
	ll dp[n][m];
	
	set<ll> s;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			a[i][j] -= (i + j);
			s.insert(a[i][j]);
		}
	}

	for (auto t : s) {
		if (a[0][0] >= t && a[n - 1][m - 1] >= t) {
			for (int i = 0; i < n; i++) 
				for (int j = 0; j < m; j++)
					dp[i][j] = -1;
					
			ll dif = a[0][0] - t;
			dp[0][0] = dif;
			
			for (int x = 1; x < m; x++) {
				dif = a[0][x] - t;
				if (dp[0][x - 1] >= 0 && dif >= 0) {
					dp[0][x] = dp[0][x - 1] + dif;
				}
				else 
					dp[0][x] = -1;
			}
				
			for (int x = 1; x < n; x++) {
				dif = a[x][0] - t;
				if (dp[x - 1][0] >= 0 && dif >= 0) {
					dp[x][0] = dp[x - 1][0] + dif;
				}
				else
					dp[x][0] = -1;
			}
				
			for (int x = 1; x < n; x++) {
				for (int y = 1; y < m; y++) {
					dif = a[x][y] - t;
					if (dif >= 0) {
						if (dp[x - 1][y] < 0 && dp[x][y - 1] < 0)
							dp[x][y] = -1;
						else if (dp[x - 1][y] < 0)
							dp[x][y] = dp[x][y - 1] + dif;
						else if (dp[x][y - 1] < 0)
							dp[x][y] = dp[x - 1][y] + dif;
						else
							dp[x][y] = min(dp[x - 1][y], dp[x][y - 1]) + dif;
					} else
						dp[x][y] = -1;
				}
			}
			if (dp[n - 1][m - 1] >= 0)
				ans = min(ans, dp[n - 1][m - 1]);
		}
	}
	cout << ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> t;
	while (t--) {
		solve();
		cout << '\n';
	}
}
