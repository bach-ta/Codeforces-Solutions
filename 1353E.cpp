#include <bits/stdc++.h>
using namespace std;

int t, n, k;
string s;

void solve() {
	cin >> n >> k >> s;
	int dp[n + 1], ans, cnt[n + 1];
	cnt[0] = 0;
	cnt[1] = s[0] - '0';
	
	for (int i = 1; i < n; i++)
		cnt[i + 1] = cnt[i] + (s[i] - '0');
	
	if (cnt[n] == 0) {
		cout << 0;
		return;
	}
	dp[n] = '1' - s[n - 1];
	ans = dp[n] + cnt[n - 1];
	for (int i = n - 1; i >= 1; i--) {
		dp[i] = cnt[n] - cnt[i];
		if (i + k <= n)
			dp[i] = min(dp[i], dp[i + k] + cnt[i + k - 1] - cnt[i]) + ('1' - s[i - 1]);
		ans = min(ans, cnt[i - 1] + dp[i]);
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
