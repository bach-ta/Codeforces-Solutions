#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	long n, l, r, end = 0, ans = 0;
	cin >> n;
	pair<long, long> p[n];
	
	for (long i = 0; i < n; i++) 
		cin >> p[i].se >> p[i].fi;
		
	sort(p, p + n);
	
	for (long i = 0; i < n; i++) {
		if (p[i].se > end) {
			end = p[i].fi;
			ans++;
		}
	}
	
	cout << ans;
}
