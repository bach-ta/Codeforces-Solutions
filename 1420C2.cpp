#include <bits/stdc++.h>
#define ll long long
#define vll vector<ll>
#define REP(i, a, n) for(int i = a; i < n; i++)
using namespace std;

int T;
ll n, q, l, r, ans;

void upd(int ind, int v, vll& a) {
	ans -= a[0];
	if (ind > 0) ans -= __max(0, a[ind]-a[ind-1]);
	if (ind < a.size()-1) ans -= __max(0, a[ind+1]-a[ind]);
	a[ind] = v;
	if (ind > 0) ans += __max(0, a[ind]-a[ind-1]);
	if (ind < a.size()-1) ans += __max(0, a[ind+1]-a[ind]);
	ans += a[0];
}

void solve() {
	cin >> n >> q;
	vll a(n);
	
	REP(i, 0, n)
		cin >> a[i];
		
	ans = a[0];
	
    REP(i, 1, n)
		ans += __max(0, a[i]-a[i-1]);
	
	cout << ans << '\n';
	
	while (q--) {
		cin >> l >> r;
		l--, r--;
		ll x = a[l];
		upd(l, a[r], a);
		upd(r, x, a);
		cout << ans << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	while (T--)
		solve();
}
