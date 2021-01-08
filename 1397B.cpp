#include <bits/stdc++.h>
#define ll long long
#define rep(i, a, n) for(int i = a; i <= n; i++)
#define REP(i, a, n) for(int i = a; i < n; i++)
using namespace std;

int T, n;
ll ans = 1e18;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	ll a[n];
	REP(i, 0, n) cin >> a[i];
	sort(a, a + n);
	
	ll ub = min((ll)pow(a[n-1], 1.0/(n-1)) + 1, (ll)pow(ans, 1.0/(n-1)));
	rep(f, 1, ub) {
		ll t = 0;
		REP(i, 0, n)
			t += abs(a[i] - pow(f, i));
		ans = min(ans, t);
	}
	cout << ans;
}
