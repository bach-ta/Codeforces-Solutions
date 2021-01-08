#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define fi first
#define se second
#define pi pair<int, int>
#define pll pair<ll, ll>
#define rep(i, a, n) for(ll i = a; i <= n; i++)
#define per(i, a, n) for(ll i = a; i >= n; i--)
#define REP(i, a, n) for(ll i = a; i < n; i++)
#define Y "YES"
#define N "NO"
using namespace std;

ll n;

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	vll a(n+1);
	vector<pll> p;
	map<ll, vll> mp;
	
	rep(i, 1, n) {
		cin >> a[i];
	}
	vll sum(n+1);
	sum[0] = 0;
	mp[0].pb(0);
	rep(i, 1, n) {
		sum[i] = sum[i-1] + a[i];
		mp[sum[i]].pb(i);
	}
	for (auto x : mp) {
		int s = x.se.size();
		REP(i, 1, s) {
			p.pb( {x.se[i-1]+1, x.se[i]} );
		}
	}
	sort(p.begin(), p.end());
	
	ll ans = p.size();
	ll s = ans;
	if (ans == 0) {
		cout << 0;
		return 0;
	}
	ll c = p[0].se;
	REP(i, 1, s) {
		if (p[i].fi < c) {
			ans--;
			c = min(c, p[i].se);
		}
		else c = p[i].se;
	}
	cout << ans;
}
