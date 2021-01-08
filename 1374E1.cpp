#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i <= n; i++)
#define REP(i, a, n) for(int i = a; i < n; i++)
#define vi vector<int>
#define pb push_back
using namespace std;

int n, k, t;
bool x, y;
vi a, b, c;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	while (n--) {
		cin >> t >> x >> y;
		if (x && y) c.pb(t);
		else if (x) a.pb(t);
		else if (y) b.pb(t);
	}
	int sa = a.size(), sb = b.size(), sc = c.size();
	int m = min(sa, sb);
	if (m + sc < k) cout << -1;
	else {
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		sort(c.begin(), c.end());
		int i = max(0, k - m), j = min(k, sc), s = 0, l = 0;
		REP(ind, 0, j) s += c[ind];
		REP(ind, 0, k-j) s += a[ind] + b[ind], l++;
		int num = j - i, ans = s;
		j--;
		while (num--) {
			s += a[l] + b[l] - c[j--];
			l++;
			ans = min(ans, s);
		}
		cout << ans;
	}
}
