#include <bits/stdc++.h>
#define REP(i, a, n) for(int i = a; i < n; i++)
using namespace std;

int T, n, k;
bool c[301][301];

void solve() {
	cin >> n >> k;
	cout << 2 * (k % n > 0) << '\n';
	
	memset(c, 0, sizeof(c));
	int i = 0, j = 0;
	while (k--) {
		c[i][j] = 1;
		i = (i+1)%n;
		j = (j+1)%n;
		if (i == 0)
			j = (j+1)%n;
	}
	REP(i, 0, n) {
		REP(j, 0, n)
			cout << c[i][j]; 
		cout << '\n'; 
	} 
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	while (T--)
		solve();
}
