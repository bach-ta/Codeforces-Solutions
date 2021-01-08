#include <bits/stdc++.h>
#define ll long long
#define vll vector<ll>
#define REP(i, a, n) for(int i = a; i < n; i++)
#define pb push_back
using namespace std;

int n;
ll a;
vll f, s, v;
bool check[3164];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	for (ll i = 2; i <= 3163; i++)
		if (!check[i])
			for (ll j = 2*i; j <= 3163; j += i)
				check[j] = 1;
	
	for (ll i = 2; i <= 3163; i++)
		if (!check[i]) v.pb(i);

	cin >> n;
	while (n--) {
		cin >> a;
		ll b = a;
		int i = 0;
		while (i < v.size() && a % v[i] != 0) i++;
		if (i == v.size()) {
			f.pb(-1);
			s.pb(-1);
		} else {
			while (a % v[i] == 0) a /= v[i];
			if (a > 1) f.pb(a), s.pb(b/a);
			else f.pb(-1), s.pb(-1);
		}
	}
	for (auto x : f) cout << x << " ";
	cout << '\n';
	for (auto x : s) cout << x << " ";
}
