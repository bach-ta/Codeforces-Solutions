#include <bits/stdc++.h>
#define ll long long
#define vll vector<ll>
#define rep(i, a, n) for(int i = a; i <= n; i++)
using namespace std;

int T, n, k;

void solve() {
	cin >> n;
	vll a(n+1), f(n+1, 0), l(n+1, 0), ans(n+1, -1);
	rep(i, 1, n) {
		cin >> a[i];
		f[a[i]] = max(f[a[i]], i - l[a[i]]);
		l[a[i]] = i;
	}
	rep(x, 1, n) {
		f[x] = max(f[x], n - l[x] + 1);
		for (int i = f[x]; i <= n && ans[i] == -1; i++)
			ans[i] = x;
	}
	rep(i, 1, n) cout << ans[i] << " ";
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
