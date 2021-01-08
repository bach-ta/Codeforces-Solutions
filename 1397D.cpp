#include <bits/stdc++.h>
#define vi vector<int>
using namespace std;

int T, n;

void solve() {
	cin >> n;
	vi a(n);
	for (int &x : a) cin >> x;
	int m = *max_element(a.begin(), a.end());
	int s = accumulate(a.begin(), a.end(), 0);
	if (m > s - m || s % 2) cout << 'T';
	else cout << "HL";
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
