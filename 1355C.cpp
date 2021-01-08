#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll a, b, c, d, ans;

ll cnt(ll a, ll b) {
	if (a > b) return 0;
	return b - a + 1;
}

void solve() {
	cin >> a >> b >> c >> d;
	
	for (ll i = max(a + b, c); i <= b + c; i++)
        ans += cnt(max(a, i - c), min(b, i - b)) * cnt(c, min(d, i - 1));
	cout << ans;
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	solve();
}
