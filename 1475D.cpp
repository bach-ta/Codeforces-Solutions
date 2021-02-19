#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define fi first
#define se second
#define rep(i, a, n) for(int i = a; i <= n; i++)
#define REP(i, a, n) for(int i = a; i < n; i++)
using namespace std;

ll T, n, m;

void solve() {
	cin >> n >> m;
	ll a[n], b[n], ans = 0;
	ll suma = 0, sumb = 0;
	vector<ll> v1, v2;
	rep(i, 0, n-1) {
		cin >> a[i];
		suma += a[i];
	}
	rep(i, 0, n-1) {
		cin >> b[i];
		sumb += b[i];
		if (b[i] == 1) v1.pb(a[i]);
		else v2.pb(a[i]);
	}
	if (suma < m) {
		cout << -1;
		return;
	}
	sort(v1.begin(), v1.end(), greater<>());
	sort(v2.begin(), v2.end(), greater<>());
	ll s1 = v1.size(), s2 = v2.size();

	if (!s1) {
		int k = 0;
		int mem = 0;
		while (k < s2 && mem < m) {
			mem += v2[k];
			k++;
		}
		cout << 2 * k;
		return;
	}

	ll dp[sumb+1];
	pair<ll, ll> p[sumb + 1];
	ll ia = 0, ib = 0;

	dp[0] = 0;
	p[0] = {-1, -1};
	rep(i, 1, sumb) {
		ll o1 = -1, o2 = -1;
		
		if (p[i-1].fi >= s1 - 1 && p[i-2].se >= s2 - 1) {
			cout << -1;
			break;
		}
		if (p[i-1].fi < s1 - 1) o1 = dp[i-1] + v1[p[i-1].fi+1];
		if (i < 2) {
			dp[i] = dp[i-1];
			p[i] = p[i-1];
		}
		else if (p[i-2].se < s2 - 1) o2 = dp[i-2] + v2[p[i-2].se+1];

		if (o1 > o2) {
			dp[i] = o1;
			p[i] = {p[i-1].fi + 1, p[i-1].se};
		} else {
			dp[i] = o2;
			p[i] = {p[i-2].fi, p[i-2].se + 1};
		}
		if (dp[i] >= m) {
			cout << i;
			break;
		}
	}
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
