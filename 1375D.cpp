#include <bits/stdc++.h>
#define vi vector<int>
#define pb push_back
#define ppb pop_back()
#define REP(i, a, n) for(int i = a; i < n; i++)
#define per(i, a, n) for(int i = a; i >= n; i--)
using namespace std;

int T, n, a;

void solve() {
	cin >> n;
	int a[n], cnt[n];
	
	REP(i, 0, n)
		cnt[i] = 0;
		
	vi u, v;
	
	REP(i, 0, n) {
		cin >> a[i];
		if (a[i] >= n) v.pb(i);
		else {
			cnt[a[i]]++;
			if (cnt[a[i]] > 1) v.pb(i);
		}
	}
	
	per(i, n-1, 0)
		if (cnt[i] == 0)
			u.pb(i);
	
	int s = v.size();
	
	REP(i, 0, s) {
		a[v[i]] = u.back();
		u.ppb;
	}
	
	bool check[n];
	int mex = 0;
	
	REP(i, 0, n) {
		if (a[i] == i) {
			check[i] = 1;
			if (i == mex) mex++;
		}
		else
			check[i] = 0;
	}
	
	int i = mex, b = mex;
	
	while (mex < n) {
		if (check[i]) {
			v.pb(i);
			i = mex;
			b = mex;
		}
		else {
			check[i] = 1;
			if (i == mex) {
				while (mex < n && check[mex])
					mex++;
			}
			v.pb(i);
			i = a[i];
		}
	}
	
	if (b < n) v.pb(b);
	
	cout << v.size() << '\n';
	for (auto x : v) cout << x + 1 << " ";
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
