#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll T, n;

ll q(ll l, ll r) {
	cout << "? " << l << " " << r << '\n';
	fflush(stdout);
	ll a;
	cin >> a;
	return a;
}

int main() {
	cin >> n;
	ll sm = q(1, n);
	if (sm > 1 && q(1, sm) == sm) {
		ll l = 1, r = sm;
		while (r != l + 1) {
			ll mid = (l + r) >> 1;
			if (q(mid, sm) == sm)
				l = mid;
			else
				r = mid;
		}
		cout << "! " << l << '\n';
	} else {
		ll l = sm, r = n;
		while (r != l + 1) {
			ll mid = (l + r) >> 1;
			if (q(sm, mid) == sm)
				r = mid;
			else
				l = mid;
		}
		cout << "! " << r << '\n';
	}
	fflush(stdout);
}
