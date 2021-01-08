#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define ppb pop_back()
#define fi first
#define se second
#define pi pair<int, int>
#define rep(i, a, n) for(int i = a; i <= n; i++)
#define REP(i, a, n) for(int i = a; i < n; i++)
#define Y "YES"
#define N "NO"
using namespace std;

int T, n;

void solve() {
	cin >> n;
	int a[n+1], cnt = 0;
	vi v;
	rep(i, 1, n) {
		cin >> a[i];
		if (a[i] != i) {
			cnt++;
			v.pb(i);
		}
	}
	bool b = 1;
	int s = v.size();
	REP(i, 1, s) 
		if (v[i] - v[i-1] != 1) {
			b = 0;
			break;
		}
		
	if (cnt == 0) cout << 0;
	else if (cnt == n || b) cout << 1;
	else cout << 2;
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
