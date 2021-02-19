#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll T, n, x, y;

void solve() {
	cin >> x >> y;
	ll ans = 0;
	ll s = sqrt(x);
	for (ll c = 1; c <= s; c++) {
		ans += __max(0, __min(y, x/c - 1) - c);
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
