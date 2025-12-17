#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

struct Bit {// 0 ~ n - 1
	vector <u64> v;
	int n = 0, rn = 0;
	Bit () {n = 0;}
	Bit (int _n) {init(_n);}
	void init(int _n) {
		this -> n = _n;
		v.resize((n + 63) / 64);
		rn = v.size();
	}
	void reset() {fill(v.begin(), v.end(), 0);}
	void set(const int &x, const int &y) {y ? set1(x) : set0(x);}
	void set0(const int &x) {assert(x < n); v[x >> 6] &= ~(1ull << (x & 63));}
	void set1(const int &x) {assert(x < n); v[x >> 6] |= (1ull << (x & 63));}
	void flip(const int &x) {assert(x < n); v[x >> 6] ^= (1ull << (x & 63));}
	void filp() {for (int i = 0; i < rn; i++) v[i] = ~v[i];}
	bool operator [](const int &x) {assert(x < n); return (v[x >> 6] >> (x & 63)) & 1;}
	Bit operator ~ () const {
		Bit res(n);
		for (int i = 0; i < rn; i++) res.v[i] = ~v[i];
		return res;
	}
	Bit operator &= (const Bit &rhs) {
		for (int i = 0; i < rn; i++) v[i] &= rhs.v[i];
		return *this;
	}
	Bit operator |= (const Bit &rhs) {
		for (int i = 0; i < rn; i++) v[i] |= rhs.v[i];
		return *this;
	}
	Bit operator ^= (const Bit &rhs) {
		for (int i = 0; i < rn; i++) v[i] ^= rhs.v[i];
		return *this;
	}
	friend Bit operator & (Bit a, const Bit &rhs) {return a &= rhs;}
	friend Bit operator | (Bit a, const Bit &rhs) {return a |= rhs;}
	friend Bit operator ^ (Bit a, const Bit &rhs) {return a ^= rhs;}
	Bit operator << (const int &t) const {
		const int high = t >> 6, low = t & 63;
		u64 lst = 0;
		Bit res(n);
		for (int i = 0; i + high < rn; i++) {
			res.v[i + high] = lst | (v[i] << low);
			if (low) lst = v[i] >> (64 - low);
		}
		return res;
	}
	Bit operator >> (const int &t) const {
		const int high = t >> 6, low = t & 63;
		u64 lst = 0;
		Bit res(n);
		for (int i = rn - 1; i >= high; i--) {
			res.v[i - high] = (lst | (v[i] >> low));
			if (low) lst = v[i] << (64 - low);
		}
		return res;
	}
	Bit operator <<= (const int &t) {*this << t; return *this;}
	Bit operator >>= (const int &t) {*this >> t; return *this;}
	bool operator == (const Bit &rhs) const {
		for (int i = 0; i < rn; i++) if (v[i] != rhs.v[i]) return 0;
		return 1;
	}
	bool operator != (const Bit &rhs) const {
		for (int i = 0; i < rn; i++) if (v[i] != rhs.v[i]) return 1;
		return 0;
	}
	bool any() const {
		for (int i = 0; i < rn; i++) if (v[i]) return 1;
		return 0;
	}
	bool none() const {
		for (int i = 0; i < rn; i++) if (v[i]) return 0;
		return 1;
	}	
	int count() const {
		int res = 0;
		for (int i = 0; i < rn; i++) res += __builtin_popcountll(v[i]);
		return res;
	}
	int find_first(const int st = 0) const { // start st
		int i = st >> 6, low = st & 63;
		if ((v[i] >> low)) {
			int j = low;
			while (1) {
				if (v[i] >> j & 1) return (i << 6) + j;
				j++;
			}
		}
		i++;
		while (i < rn) {
			if (v[i]) {
				int j = 0;
				while (1) {
					if (v[i] >> j & 1) return (i << 6) + j;
					j++;
				}
			}
			i++;
		}
		return -1;
	}
	int find_last(const int st = -1) const { // start st
		int i = (st == -1 ? rn - 1 : (st >> 6)), low = (st == -1 ? ((n - 1) & 63) : (st & 63));
		if ((v[i] << (63 - low))) {
			int j = low;
			while (1) {
				if (v[i] >> j & 1) return (i << 6) + j;
				j--;
			}
		}
		i--;
		while (i >= 0) {
			if (v[i]) {
				int j = 63;
				while (1) {
					if (v[i] >> j & 1) return (i << 6) + j;
					j--;
				}			
			}
			i--;
		}
		return -1;
	}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    Bit bs(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            bs.set1(i);
        }
    }

    for (int i = 0; i < q; i++) {
        
    }

    return 0;
}

/*
10 3
1001001001
2 4 3 5
1 2 6
2 5 2 6

*/
