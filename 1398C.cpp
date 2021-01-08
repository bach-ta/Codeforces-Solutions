#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define REP(i, a, n) for(int i = a; i < n; i++)
using namespace std;

int T, n;
string s;

void solve() {
	cin >> n >> s;
	int a[n];
	ll sum[n], ans = 0;
	
	REP(i, 0, n) 
	    a[i] = s[i] - '0' - 1;
	
	sum[0] = a[0];
	map<ll, ll> mp;
	mp[sum[0]]++;
	REP(i, 1, n) {
	    sum[i] = sum[i-1] + a[i];
	    mp[sum[i]]++;
	}
	for (auto x : mp) {
	    ll m = x.second;
	    ans += m * (m-1) / 2;
	    if (x.fi == 0) ans += m;
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
