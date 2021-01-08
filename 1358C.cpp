#include <bits/stdc++.h>
#define ll long long
using namespace std;

int t;
ll x1, x2, y1, y2, x, y;

void solve() {
	cin >> x1 >> y1 >> x2 >> y2;
	x = x2 - x1;
	y = y2 - y1;
	cout << x * y + 1;
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		solve();
		cout << '\n';
	}
}
