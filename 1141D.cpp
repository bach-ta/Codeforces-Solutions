#include <bits/stdc++.h>
#define vi vector<int>
#define pi pair<int, int>
#define pb push_back
#define fi first
#define se second
using namespace std;

vector<pi> ans;

void p(vi& a, vi& b, vi& c, vi& d) {
	int minsize = min(a.size(), b.size());
	int maxsize = max(a.size(), b.size());
	for (int i = 0; i < minsize; i++)
		ans.pb({a[i], b[i]});
	
	for (int i = minsize; i < maxsize; i++) {
		if (a.size() > minsize) c.pb(a[i]);
		else d.pb(b[i]);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	string l, r;
	
	cin >> n >> l >> r;
	
	vi le[27], ri[27];

	for (int i = 0; i < n; i++) {
		if(l[i] == '?') le[26].pb(i + 1);
		else le[l[i] - 'a'].pb(i + 1);
		
		if(r[i] == '?') ri[26].pb(i + 1);
		else ri[r[i] - 'a'].pb(i + 1);
	}
	
	vi reml, remr, ql, qr, trash;
	
	for (int i = 0; i < 26; i++)
		p(le[i], ri[i], reml, remr);
	
	p(le[26], remr, ql, trash);
	p(reml, ri[26], trash, qr);
	p(ql, qr, trash, trash);
	
	cout << ans.size() << '\n';
	for (auto x : ans)
		cout << x.fi << " " << x.se << '\n';
}
