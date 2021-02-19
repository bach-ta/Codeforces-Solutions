#include <bits/stdc++.h>
#define ll long long
#define Y "YES"
#define N "NO"
using namespace std;

ll T, n;

void solve() {
	cin >> n;
	ll a[n];
	cin >> a[0];
	if (n == 1) {
		cout << Y;
		return;
	}
	ll bank = a[0];
	a[0] = 0;
	bool ans = 1;
	for (int i = 1; i < n; i++) {
		cin >> a[i];
		bank += (a[i] - a[i-1] - 1);
		a[i] = a[i-1] + 1;
		if (bank < 0) {
			ans = 0;
		}
	}
	cout << (ans ? Y : N);
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
