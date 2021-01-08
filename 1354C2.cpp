#include <bits/stdc++.h>
#define PI 3.14159265358979323846
using namespace std;

int t;
float n;

void solve() {
	cin >> n;
	float a = (n - 1) / 2;
	float b = n - a;
	cout << fixed << setprecision(8) << (sqrt(1 - cos(a*PI/n)) + sqrt(1 - cos(b*PI/n))) / (2 * sin(PI / (n * 2)));
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
