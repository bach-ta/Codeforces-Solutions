#include <bits/stdc++.h>
#define ll long long
#define Y "YES"
#define N "NO"
using namespace std;

ll T, n, m, k;

void solve() {
	ll m, k;
	cin >> n >> m >> k;
	cout << (k == m * n - 1 ? Y : N);
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
