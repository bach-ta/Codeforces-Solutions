#include <bits/stdc++.h>
#define REP(i, a, n) for(int i = a; i < n; i++)
using namespace std;

int T, cnt[10];
string s;

void solve() {
	cin >> s;
	int n = s.length(), ans = 0;
	memset(cnt, 0, sizeof(cnt));
	REP(i, 0, n) {
		cnt[(int)s[i] - 48]++;
		ans = max(ans, cnt[(int)s[i] - 48]);
	}
	ans = n - ans;
	REP(i, 0, 9) {
		REP(j, i+1, 10) {
			bool b = 0;
			int c = 0;
			int z2 = 0;
			while (z2 < n && (int)s[z2] - 48 != i && (int)s[z2] - 48 != j) z2++;
			if (z2 == n) {
				break;
			} else {
				c++;
				if ((int)s[z2] - 48 == i) b = 1;
				REP(z, z2, n) {
					if ((!b && (int)s[z] - 48 == i) || (b && (int)s[z] - 48 == j)) {
						c++;
						b = !b;
					}
				}
				if (c%2) c--;
				ans = min(ans, n-c);
			}
		}
	}
	cout << ans;
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
