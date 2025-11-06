#include <bits/stdc++.h>
using namespace std;

#define QwQ01AwA return 0
#define ll long long
#define look_time cerr << 1.0 * clock() / CLOCKS_PER_SEC << '\n'
template <typename T> void ckmax(T &x, T y) {x = max(x, y);}
template <typename T> void ckmin(T &x, T y) {x = min(x, y);}

void solve() {
	ll n;
	cin >> n;
	vector <ll> p;
	for (int i = 0; i < 60; i++) {
		if (n & (1ll << i)) p.push_back(1ll << i);
	}
	if (p.size() == 1) {
		cout << 1 << '\n' << p[0] << '\n';
		return ;
	}
	cout << p.size() + 1 << '\n';
	for (int i = p.size() - 1; i >= 0; i--) {
		ll sum = 0;
		for (auto x : p) {
			if (x != p[i]) sum += x;
		}
		cout << sum << ' ';
	}
	ll sum = 0;
	for (auto x : p) sum += x;
	cout << sum << '\n';	
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	QwQ01AwA;
}