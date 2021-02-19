#include <bits/stdc++.h>
#define ll long long
#define REP(i, a, n) for(int i = a; i < n; i++)
using namespace std;

ll T, n;

void solve() {
	cin >> n;
	ll a[n], b[n];
	REP(i, 0, n)
		cin >> a[i] >> b[i];
	sort(a, a + n);
	sort(b, b + n);
	cout << (a[n/2] - a[n-1 - n/2] + 1) * (b[n/2] - b[n-1 - n/2] + 1);
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
