#include <bits/stdc++.h>
#define REP(i, a, n) for(int i = a; i < n; i++)
#define ll long long
using namespace std;

ll k, m;
int i, cnt;
char c[10] = {'c', 'o', 'd', 'e', 'f', 'o', 'r', 'c', 'e', 's'};

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> k;
	
	i = pow(k, 1.0/10);
	m = pow(i, 10);
	
	while (m < k) {
		m /= i;
		m *= (i+1);
		cnt++;
	}
	REP(z, 0, 10-cnt)
		REP(j, 0, i)
			cout << c[z];
	REP(z, 10-cnt, 10)
		REP(j, 0, i+1)
			cout << c[z];
}
