#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i <= n; i++)
#define REP(i, a, n) for(int i = a; i < n; i++)
using namespace std;

int T, n, k, a, b, m;
string s;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k >> s;
	int cnt[n+1];
	cnt[0] = 0;
	
	rep(i, 1, n)
		cnt[i] = cnt[i-1] + (s[i-1] == 'a');
	
	b = n;
	while (a <= b) {
		m = (a + b) >> 1;
		REP(i, 0, n-m+1) {
			int x = cnt[i + m] - cnt[i];
			if (x <= k || m-x <= k) {
				a = m+1;
				break;
			}
		}
		if (a != m + 1) b = m-1;
	}
	cout << b;
}
