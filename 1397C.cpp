#include <bits/stdc++.h>
#define ll long long
#define REP(i, a, n) for(int i = a; i < n; i++)
using namespace std;

int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	ll a[n];
	REP(i, 0, n)
		cin >> a[i];
	cout << 1 << " " << 1 << '\n';
	cout << -a[0] << '\n';
	a[0] = 0;
	if (n == 1) {
		REP(i, 0, 2)
			cout << 1 << " " << 1 << '\n' << 0 << '\n';
		return 0;
	}
	cout << 2 << " " << n << '\n';
	REP(i, 1, n) {
		ll add = (a[i] % n) * (n - 1);
		a[i] += add;
		cout << add << " ";
	}
	cout << '\n' << 1 << " " << n << '\n';
	REP(i, 0, n)
		cout << -a[i] << " ";
}
