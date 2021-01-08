#include <bits/stdc++.h>
#define ll long long
#define REP(i, a, n) for(int i = a; i < n; i++)
using namespace std;

int T, n;

void solve() {
	cin >> n;
	ll a[n], ans = 0;
	REP(i, 0, n) {
		cin >> a[i];
		if (i % 2 == 0) {
			ans += a[i];
			a[i] = -a[i];
		}
	}
	ll b[n/2];
	int size = n/2;
	REP(i, 0, size)
		b[i] = a[2*i] + a[2*i+1];
	
	ll m = b[0], c = 0;
        
    for (int i = 0; i < size; i++) {
        c += b[i];
        c = __max(c, b[i]);
        m = __max(m, c);
    }
    ll m1 = m;
	
	if (n % 2 == 0) size--;
	REP(i, 0, size)
		b[i] = a[2*i+1] + a[2*i+2];
	m = b[0], c = 0;
        
    for (int i = 0; i < size; i++) {
        c += b[i];
        c = __max(c, b[i]);
        m = __max(m, c);
    }
    m = max(m, m1);
	cout << max(ans, ans + m);
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
