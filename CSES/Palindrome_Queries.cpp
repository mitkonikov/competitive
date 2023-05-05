#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const int MOD = 1e9 + 7; // Has to be prime
const pll BASE = {4441, 7817}; // they are both prime here (as well)

pll operator+(const pll& a, const pll& b) {
	return { (a.first + b.first) % MOD, (a.second + b.second) % MOD };
}
pll operator+(const pll& a, const ll& b) {
	return { (a.first + b) % MOD, (a.second + b) % MOD };
}
pll operator-(const pll& a, const pll& b) {
	return { (MOD + a.first - b.first) % MOD, (MOD + a.second - b.second) % MOD };
}
pll operator*(const pll& a, const pll& b) {
	return { (a.first * b.first) % MOD, (a.second * b.second) % MOD };
}
pll operator*(const pll& a, const ll& b) {
	return { (a.first * b) % MOD, (a.second * b) % MOD };
}

inline ll modpow(ll x, int p) {
	if (!p) return 1;
	return (modpow(x * x % MOD, p >> 1) * (p % 2 ? x : 1)) % MOD;
}

inline ll modinv(ll x) {
	return modpow(x, MOD - 2);
}

pll get_hash(string s) {
	pll h = {0, 0};
	for (int i = s.size() - 1; i >= 0; i--) {
		h = BASE * h + s[i];
	}
	return h;
}

struct HashBit {
	int N;
	string S;
	vector<pll> fen, pp, ipp;

	void init(string S_) {
		S = S_;
		N = S.size();
		fen.resize(N + 1);
		pp.resize(N); ipp.resize(N);
		pp[0] = ipp[0] = {1, 1};
		const pll ibase = {modinv(BASE.first), modinv(BASE.second)};
		for (int i = 1; i < N; i++) {
			pp[i] = pp[i - 1] * BASE;
			ipp[i] = ipp[i - 1] * ibase;
		}
		for (int i = 0; i < N; i++) {
			upd(i, S[i]);
		}
	}

	void upd(int i, int x) {
		pll p = pp[i] * x;
		for (++i; i <= N; i += i & -i) {
			fen[i] = fen[i] + p;
		}
	}

	pll qry(int i) {
		pll ret = {0, 0};
		for (; i; i -= i & -i) {
			ret = ret + fen[i];
		}
		return ret;
	}

	void set(int i, char c) {
		int d = (MOD + c - S[i]) % MOD;
		S[i] = c;
		upd(i, d);
	}

	pll get(int s, int e) { // [s, e)
		return (qry(e) - qry(s)) * ipp[s];
	}
};

int main() {
    int N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;
	HashBit hash, hash_back;
    hash.init(S);
    string RS = S;
    reverse(RS.begin(), RS.end());
    hash_back.init(RS);
    for (int i = 0; i < Q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int x;
            char c;
            cin >> x >> c;
            x--;

            hash.set(x, c);
            hash_back.set(N - 1 - x, c);
        } else {
            int l, r;
            cin >> l >> r;
            l--; r--;

            auto h1 = hash.get(l, r);
            auto h2 = hash_back.get(N - 1 - r, N - 1 - l);
            cout << (h1 == h2 ? "YES" : "NO") << endl;
        }
    }
	return 0;
}
