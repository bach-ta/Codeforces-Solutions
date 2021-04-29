#include <bits/stdc++.h>
#define ll long long
#define vll vector<ll>
#define pb push_back
#define fi first
#define se second
#define rep(i, a, n) for(int i = a; i <= n; i++)
#define REP(i, a, n) for(int i = a; i < n; i++)
using namespace std;

ll T, n;

void solve() {
	cin >> n;
	vector<vll> u(n); 

	ll U[n], s;
	ll len[n] = {0};

	REP(i, 0, n) {
		cin >> U[i];
		U[i]--;
	}

	REP(i, 0, n) {
		cin >> s;
		u[U[i]].pb(s);
		len[U[i]]++;
	}

	REP(i, 0, n) {
		sort(u[i].begin(), u[i].end(), greater<ll>());
		REP(j, 1, len[i]) {
			u[i][j] += u[i][j - 1];
		}
	}

	vector<pair<ll, vll>> v;
	ll cnt = 0;

	REP(i, 0, n) {
		if (len[i]) {
			v.pb({len[i], u[i]});
			cnt++;
		}
	}

	sort(v.begin(), v.end(), greater<pair<ll, vll>>());

	rep(k, 1, n) {
		ll ans = 0;
		REP(i, 0, cnt) {
			if (v[i].fi < k) break;
			ans += v[i].se[v[i].fi - v[i].fi % k - 1];
		}
		cout << ans << " ";
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
