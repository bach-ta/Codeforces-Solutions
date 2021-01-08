#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define all(v) (v).begin(),(v).end()
#define SUM(v) accumulate(all(v), 0)
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

int T;
ll a, n, x;

void solve() {
	cin >> n >> x;
	ll sum = 0, c = 0;
	REP(i, 0, n) {
		cin >> a;
		sum += a;
		c += (a == x);
	}
	if (c == n) cout << 0;
	else if (c > 0 || n * x == sum) cout << 1;
	else cout << 2;
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
