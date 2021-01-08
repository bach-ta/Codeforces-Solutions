#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define fi first
#define se second
#define pi pair<int, int>
#define rep(i, a, n) for(int i = a; i <= n; i++)
#define REP(i, a, n) for(int i = a; i < n; i++)
#define Y "YES"
#define N "NO"
using namespace std;

int T;
ll p, f, cs, cw, s, w;

void solve() {
	cin >> p >> f >> cs >> cw >> s >> w;
	ll ans = 0;
	if (s < w) {
		swap(s, w);
		swap(cs, cw);
	}
	if (p > f) swap(p, f);
	ll k = __min(p/w, cw);

	rep(i, 0, k) {
		ll p2 = p - i * w, f2 = f;
		ll cw2 = cw - i, cs2 = cs;
		ll x = __min(p2/s, cs2);
			cs2 -= x;
		x = __min(f2/w, cw2);
			f2 -= x*w;
			cw2 -= x;
		x = __min(f2/s, cs2);
			f2 -= x*s;
			cs2 -= x;
		ans = __max(ans, cs + cw - cs2 - cw2);
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
