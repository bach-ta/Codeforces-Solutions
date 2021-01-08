#include <bits/stdc++.h>
using namespace std;

double c, h, t, a, k, x;
int T, q, p;

void solve() {
	cin >> h >> c >> t;
	a = (h + c) / 2;
	if (t <= a) cout << 2;
	else {
		x = (h - a) / (t - a);
		
		k = h - a;
		q = (int)x;
		t -= a;
		
		if (q % 2 == 0) p = q - 1, q++;
		else p = q + 2;
		
		if (abs(k / q - t) < abs(k / p - t)) cout << q;
		else if (abs(k / q - t) > abs(k / p - t)) cout << p;
		else cout << min(p, q);
	}
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
