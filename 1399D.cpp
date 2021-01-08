#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define all(v) (v).begin(),(v).end()
#define SUM(v) accumulate(all(v), 0)
#define pb push_back
#define fi first
#define se second
#define pi pair<int, int>
#define rep(i, a, n) for(int i = a; i <= n; i++)
#define per(i, a, n) for(int i = a; i >= n; i--)
#define REP(i, a, n) for(int i = a; i < n; i++)
#define Y "YES"
#define N "NO"
using namespace std;

int T, n, a[200001];
string s;
queue<int> r[2];

void solve() {
	cin >> n >> s;

	queue<int> empty;
	r[0] = r[1] = empty;

	int ans = 1;
	r[!(s[0]-'0')].push(1);
	a[0] = 1;

	REP(i, 1, n) {
		bool b = s[i] - '0';
		if (r[b].empty()) {
			ans++;
			r[!b].push(ans);
			a[i] = ans;
		} else {
			a[i] = r[b].front();
			r[b].pop();
			r[!b].push(a[i]);
		}
	}
	cout << ans << '\n';
	REP(i, 0, n) cout << a[i] << " ";
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
