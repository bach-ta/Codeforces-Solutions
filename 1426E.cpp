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

ll n, r[2], p[2], s[2];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	REP(i, 0, 2)
		cin >> r[i] >> s[i] >> p[i];
	ll maxa = min(r[0], s[1]) + min(s[0], p[1]) + min(p[0], r[1]);
	ll x, y, z;
	x = min(r[0], r[1]+p[1]);
	y = min(s[0], s[1]+r[1]);	
	z = min(p[0], p[1]+s[1]);
	cout << r[1] + s[1] + p[1] - x - y - z << " " << maxa;
}
