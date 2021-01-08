#include <bits/stdc++.h>
#define ll long long
#define Y "YES"
#define N "NO"
using namespace std;

int t;
ll n, i;

void solve() {
	cin >> n;
	
	ll r[n], a[n];
	i = 0;
	
	for (int i = 0; i < n; i++) 
	    r[i] = 1;

	for (ll i = 0; i < n; i++) {
		cin >> a[i];
		r[i]--;
		r[(a[i] % n + i + n) % n]++;
	}
	
	while (i < n && r[i] == 1)
	    i++;
	    
	if (i == n) cout << Y;
	else cout << N;
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
