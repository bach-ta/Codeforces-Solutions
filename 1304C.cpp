#include <bits/stdc++.h>
#define ll long long
#define REP(i, a, n) for(int i = a; i < n; i++)
#define Y "YES"
#define N "NO"
using namespace std;

int T, n;
ll t, m, a, b;

void solve() {
	cin >> n >> m;
	ll x = m, y = m, k = 0;
	bool ans = 1;
	while (n--) {
		cin >> t >> a >> b;
		x -= t - k;
		y += t - k;
		if (a > y || b < x) ans = 0;
		x = __max(x, a);
		y = __min(y, b);
		k = t;
	}
	if (ans) cout << Y;
	else cout << N;
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
