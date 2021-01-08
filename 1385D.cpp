#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define ppb pop_back()
#define pf push_front
#define ppf pop_front()
#define fi first
#define se second
#define pi pair<int, int>
#define ppi pair<pi, pi>
#define rep(i, a, n) for(int i = a; i <= n; i++)
#define REP(i, a, n) for(int i = a; i < n; i++)
using namespace std;

int T, n;
string s;
char c[18] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r'};

ll cnt(string s, int i) {
	ll a = 0;
	REP(x, 0, s.length())
		if (s[x] != c[i]) a++;
	return a;
}

ll m(string s, int i) {
	int n = s.length();
	if (n == 1)
		return s[0] != c[i];
	return min(cnt(s.substr(0, n/2), i) + m(s.substr(n/2, n/2), i+1), cnt(s.substr(n/2, n/2), i) + m(s.substr(0, n/2), i+1));
}

void solve() {
	cin >> n >> s;
	cout << m(s, 0);
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
