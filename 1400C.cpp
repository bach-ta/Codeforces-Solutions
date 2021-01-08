#include <bits/stdc++.h>
#define REP(i, a, n) for(int i = a; i < n; i++)
using namespace std;

int T, x, n;
string s;

void solve() {
	cin >> s >> x;
	n = s.length();
	bool a[n], ans = 0;
	REP(i, 0, n) a[i] = 1;
	REP(i, 0, n) {
		if (s[i] == '0') {
			if (i - x >= 0) a[i-x] = 0;
			if (i + x < n) a[i+x] = 0;
		}
	}
	REP(i, 0, n) {
		if (s[i] == '1') {
			if (    !((i - x >= 0 && a[i-x]) || (i + x < n && a[i+x]))    ) {
				ans = 1;
				break;
			}
		}
	}
	if (ans) cout << -1;
	else REP(i, 0, n) cout << a[i];
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
