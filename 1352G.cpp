#include <bits/stdc++.h>
using namespace std;

int t, n;

void solve() {
	cin >> n;
	if (n < 4) cout << -1;
	else if (n == 4) cout << "3 1 4 2";
	else {
	 	for (int i = 1; i <= n; i+=2) cout << i << " ";
		if (n%2 == 0) {
			cout << n - 4 << " " << n << " " << n - 2 << " ";
			for (int i = n - 6; i > 1; i-=2) cout << i << " ";
		} else {
			cout << n - 3 << " " << n - 1 << " ";
			for (int i = n - 5; i > 1; i-=2) cout << i << " ";
		}
	}
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
