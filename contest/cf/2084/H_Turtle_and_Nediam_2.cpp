#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

const i64 P = 998244353;

i64 power(i64 a, i64 b) {
	i64 res = 1;
	for (; b; b /= 2, a = a * a % P) {
		if (b % 2 == 1) {
			res = res * a % P;
		}
	}
	return res;
}
i64 norm(i64 x) {
	if (x >= P) {
		x -= P;
	}
	if (x < 0) {
		x += P;
	}
	return x;
}
i64 cadd(i64 x, i64 y) {
	x = norm(x);
	y = norm(y);
	x += y;
	return norm(x);
}
i64 cmul(i64 x, i64 y) {
	x = norm(x);
	y = norm(y);
	return x * y % P;
}
i64 inv(i64 x) {
	return power(x, P - 2);
} 
i64 cdiv(i64 x, i64 y) {
	x = norm(x);
	y = norm(y);
	return cmul(x, inv(y));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}