#include <bits/stdc++.h>
#define ll long long
#define Y "YES"
#define N "NO"
using namespace std;

ll T, r, b, d;

void solve() {
	cin >> r >> b >> d;
	if (r > b) swap(r, b);
	cout << (b <= r + r * d ? Y : N);
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
