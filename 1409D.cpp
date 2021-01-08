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

int T, s;
string num;

ll toint(string str) {
	int l = str.length();
	ll res = 0;
	for (int i = 0; i < l; i++)
		res = res * 10 + (str[i] - '0');
	return res;
}

void solve() {
	cin >> num >> s;
	int n = num.length();
	int i = 0, sum = 0;
	while (i < n && sum <= s) {
		sum += (num[i] - '0');
		i++;
	}
	if (sum <= s) cout << 0;
	else {
		i--;
		sum -= (num[i] - '0');
		if (sum == s) {
			i--;
			while (i >= 0 && num[i] == '0') i--;
		}
		string k = "1";
		int nn = n - i;
		while (nn--)
			k += '0';
		cout << toint(k) - toint(num.substr(i, n - i));
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
