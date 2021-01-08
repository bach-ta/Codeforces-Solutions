#include <bits/stdc++.h>
using namespace std;

int t;

void solve() {
	long n, ans = 0;
	cin >> n;
	long a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i < n; i++) {
		if (a[i] < a[i - 1]) {
			ans = max(ans, (long)log2(a[i - 1] - a[i]) + 1);
			a[i] = a[i - 1];
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
