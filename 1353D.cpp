#include <bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;

int t, n;

void solve() {
	cin >> n;
	priority_queue<pair<int, pi>> q;
	int ans[n + 1], ind;

	q.push({n, {1, n}});
	
	for (int i = 1; i <= n; i++) {
		pi seg = q.top().se;
		ind = (seg.fi + seg.se + 1)/2;
		q.push({ind - seg.fi, {seg.fi, ind-1}});
		q.push({seg.se - ind, {ind+1, seg.se}});
		ans[ind] = i;
		q.pop();
	}
	for (int i = n; i > 0; i--) cout << ans[i] << " ";
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
