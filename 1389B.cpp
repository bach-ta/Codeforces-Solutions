#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i <= n; i++)
#define REP(i, a, n) for(int i = a; i < n; i++)
using namespace std;

int T, n, k, z;

void solve() {
	cin >> n >> k >> z;
	int a[n], s[n], ans = 0;
	cin >> a[0];
	s[0] = a[0];
	REP(i, 1, n) {
		cin >> a[i];
		s[i] = s[i-1] + a[i];
	}
	rep(i, 0, z) {
		int si = k + 1 - 2 * i, m = 0;
		REP(j, 1, si+1) {
			if (si < n) m = max(m, a[j] + a[j-1]);
		}
		if (si > 0) ans = max(ans, s[si-1] + i * m);
	}
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
