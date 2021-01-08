#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define fi first
#define se second
#define pi pair<int, int>
#define rep(i, a, n) for(int i = a; i <= n; i++)
#define per(i, a, n) for(int i = a; i >= n; i--)
#define REP(i, a, n) for(int i = a; i < n; i++)
#define Y "Yes"
#define N "No"
using namespace std;

ll n, ans;
const ll mod = 998244353;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	ll a[n], b[n];
	REP(i, 0, n) {
		cin >> a[i];
		a[i] *= (i + 1) * (n - i);
	}
	sort(a, a + n);
	REP(i, 0, n) cin >> b[i];
	sort(b, b + n, greater<ll>());
	REP(i, 0, n) ans = (ans + ((a[i] % mod) * (b[i] % mod)) % mod) % mod;
	cout << ans;
}
