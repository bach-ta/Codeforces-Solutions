#include <bits/stdc++.h>
#define ll long long
#define REP(i, a, n) for(int i = a; i < n; i++)
using namespace std;

ll T, n;

ll maxx(ll a, ll b) {
	return (a > b ? a : b);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	ll a[n], b[n];
	REP(i, 0, n) cin >> a[i];
	REP(i, 0, n) cin >> b[i];

	ll max_diff = 0;
	ll prefix_sum[n];
	prefix_sum[0] = a[0] * b[0];
	REP(i, 1, n) prefix_sum[i] = prefix_sum[i-1] + a[i] * b[i];
	
	ll rev_sum[n][n];

	REP(i, 0, n) {
		rev_sum[i][i] = a[i] * b[i];
		int j = 1;
		while (i + j < n && i - j >= 0) {
			rev_sum[i - j][i + j] = rev_sum[i - j + 1][i + j - 1] + a[i - j] * b[i + j] + a[i + j] * b[i - j];
			ll f = prefix_sum[i + j] - (i - j - 1 >= 0 ? prefix_sum[i - j - 1] : 0);
			max_diff = maxx(max_diff, rev_sum[i - j][i + j] - f);
			j++;
		}
	}

	REP(i, 0, n - 1) {
		rev_sum[i][i + 1] = a[i] * b[i + 1] + a[i + 1] * b[i];
		ll f = prefix_sum[i + 1] - (i - 1 >= 0 ? prefix_sum[i - 1] : 0);
		max_diff = maxx(max_diff, rev_sum[i][i + 1] - f);
		int j = 1;
		while (i + 1 + j < n && i - j >= 0) {
			rev_sum[i - j][i + 1 + j] = rev_sum[i - j + 1][i + j] + a[i-j] * b[i + 1 + j] + a[i + 1 + j] * b[i-j];

			f = prefix_sum[i + 1 + j] - (i - j - 1 >= 0 ? prefix_sum[i - j - 1] : 0);

			max_diff = maxx(max_diff, rev_sum[i - j][i + 1 + j] - f);
			j++;
		}
	}
	cout << prefix_sum[n - 1] + max_diff;
}

