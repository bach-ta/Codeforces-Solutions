#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define fi first
#define se second
#define pi pair<int, int>
#define rep(i, a, n) for(int i = a; i <= n; i++)
#define per(i, a, n) for(int i = a; i >= n; i--)
#define REP(i, a, n) for(int i = a; i < n; i++)
#define Y "YES"
#define N "NO"
using namespace std;

int T, k, n;
string s;

void solve() {
	cin >> n >> k >> s;
	char ans[k];
	REP(i, 0, k)
		ans[i] = '?';
	bool b = 1;
	int c1 = 0, c0 = 0;
	REP(i, 0, n) {
		if (s[i] != '?') {
			int p = i % k;
			if (ans[p] == '?') {
				ans[p] = s[i];
				if (s[i] == '1') c1++;
				else c0++;
			}
			else if (s[i] != ans[p]) {
				b = 0;
				break;
			}
		}
	}
	cout << ( (c1 > k / 2 || c0 > k / 2 || !b) ? N : Y );
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
