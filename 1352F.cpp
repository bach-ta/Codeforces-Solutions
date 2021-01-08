#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;

int t;

void solve() {
	int a, b, c;
	cin >> a >> b >> c;
	if (a != 0) {
		if (b % 2 == 0 && b > 0) {
			cout << 1;
			b--;
		}
		rep(i,0,a+1) cout << 0;
		rep(i, 0, b/2) cout << "10";
		if (b > 0) rep(i, 0, c+1) cout << "1";
	} else {
		if (b % 2 == 0) {
			rep(i, 0, b/2) cout << "10";
			rep(i, 0, c + 1) cout << 1;
		} else {
			rep(i, 0, b/2 + 1) cout << "01";
			rep(i, 0, c) cout << 1;
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
