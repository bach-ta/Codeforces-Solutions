#include <bits/stdc++.h>
#define ll long long
#define REP(i, a, n) for(int i = a; i < n; i++)
using namespace std;

int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	cin >> n;
	ll c[n];
	string s[n], r[n];
	
	REP(i, 0, n) cin >> c[i];
	REP(i, 0, n) {
		cin >> s[i];
		r[i] = s[i];
		reverse(r[i].begin(), r[i].end());
	}
	
	ll dp[2][n];
	REP(x, 0, 2) 
		REP(i, 1, n)
			dp[x][i] = -1;
	dp[0][0] = 0;
	dp[1][0] = c[0];
	
	int i = 1;
	
	while (i < n && !(dp[0][i-1] == -1 && dp[1][i-1] == -1)) {
		if (dp[0][i-1] >= 0) {
			if (s[i].compare(s[i-1]) >= 0) dp[0][i] = dp[0][i-1];
			if (r[i].compare(s[i-1]) >= 0) dp[1][i] = dp[0][i-1] + c[i];
		}
		if (dp[1][i-1] >= 0) {
			if (s[i].compare(r[i-1]) >= 0) dp[0][i] = (dp[0][i] == -1) ? dp[1][i-1] : __min(dp[1][i-1], dp[0][i]);
			if (r[i].compare(r[i-1]) >= 0) dp[1][i] = (dp[1][i] == -1) ? dp[1][i-1] + c[i] : __min(dp[1][i-1] + c[i], dp[1][i]);
		}
		i++;
	}
	
	if(dp[0][n-1] + dp[1][n-1] == -2) cout << -1;
	else if (dp[0][n-1] >= 0 && dp[1][n-1] >= 0) cout << __min(dp[0][n-1], dp[1][n-1]);
	else cout << __max(dp[0][n-1], dp[1][n-1]);
}
