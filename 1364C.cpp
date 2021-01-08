#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i <= n; i++)
using namespace std;

int n, c, a;
queue<int> q;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	int b[n+1];
	rep(i, 1, n) {
		cin >> a;
		if (a == c) q.push(i);
		else {
			b[i] = c;
			rep(j, c + 1, a - 1) b[q.front()] = j, q.pop();
			c = a;
		}
	}
	
	while (!q.empty()) {
		b[q.front()] = n+1;
		q.pop();
	}
	
	rep(i, 1, n) cout << b[i] << " ";
}
