#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define fi first
#define se second
#define pi pair<int, int>
#define rep(i, a, n) for(int i = a; i <= n; i++)
#define per(i, a, n) for(int i = a; i >= n; i--)
#define REP(i, a, n) for(int i = a; i < n; i++)
#define Y "Yes"
#define N "No"
using namespace std;

int T, n;

ll nd(ll n) {
	ll cnt = 0; 
    for (ll i = 1; i <= sqrt(n); i++) { 
        if (n % i == 0) {
            if (n / i == i) 
                cnt++;
            else
                cnt = cnt + 2; 
        } 
    } 
    return cnt;
}

void solve() {
	cin >> n;
	ll d[n];
	REP(i, 0, n) cin >> d[i];
	sort(d, d + n);
	ll ans = d[0] * d[n-1];
	if (n + 2 != nd(ans)) cout << -1;
	else {
		int ub = (n - 1) / 2 + 1;
		int i = 1;
		while (i < ub && d[i] * d[n-1-i] == ans) i++;
		cout << ((i == ub) ? ans : -1);
	}
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
