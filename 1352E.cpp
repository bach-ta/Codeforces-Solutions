#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;

int t;

void solve() {
	int n;
	cin >> n;
	int a[n + 1], u[n + 1];
	bool s[n + 1];
	
	
	rep(i, 1, n + 1) {
		s[i] = 0;
		cin >> a[i];
	}
	
	u[1] = a[1];
	rep(i, 2, n + 1) {
		u[i] = u[i - 1] + a[i];
		if (u[i] <= n) s[u[i]] = 1;
		rep(j, 1, i - 1) {
			int k = u[i] - u[j];
			if (k <= n) s[u[i] - u[j]] = 1;
		}
	}
	int ans = 0;
	rep(i, 1, n + 1) {
		if (s[a[i]])
			ans++;
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
