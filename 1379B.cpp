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
using namespace std;

int T, l, r;
ll m, a, b, c;

void solve() {
	cin >> l >> r >> m;
	a = l;
	ll k = r-l;
	while ((m % a > k || m < a) && (m % a - a < -k)) a++;
	if (m % a <= k && m >= a) {
		b = m % a + l;
		c = l;
	} else {
		b = l;
		c = l - m % a + a;
	}
	cout << a << " " << b << " " << c;
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
