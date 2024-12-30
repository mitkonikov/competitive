#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

// Arithmetic mod 2^64-1. 2x slower than mod 2^64 and more
// code, but works on evil test data (e.g. Thue-Morse, where
// ABBA... and BAAB... of length 2^10 hash the same mod 2^64).
// "typedef ull H;" instead if you think test data is random,
// or work mod 10^9+7 if the Birthday paradox is not a problem.
typedef uint64_t ull;
struct H {
	ull x; H(ull x=0) : x(x) {}
	H operator+(H o) { return x + o.x + (x + o.x < x); }
	H operator-(H o) { return *this + ~o.x; }
	H operator*(H o) { auto m = (__uint128_t)x * o.x;
		return H((ull)m) + (ull)(m >> 64); }
	ull get() const { return x + !~x; }
	bool operator==(H o) const { return get() == o.get(); }
	bool operator<(H o) const { return get() < o.get(); }
};
static const H C = (ll)1e11+3; // (order ~ 3e9; random also ok)

struct HashInterval {
	vector<H> ha, pw;
	HashInterval(string& str) : ha(str.size()+1), pw(ha) {
		pw[0] = 1;
		for (int i = 0; i < str.size(); i++)
			ha[i+1] = ha[i] * C + str[i],
			pw[i+1] = pw[i] * C;
	}
	H hashInterval(int a, int b) { // hash [a, b)
		return ha[b] - ha[a] * pw[b - a];
	}
};


int main() {
    int K;
    cin >> K;
    string S, T;
    cin >> S >> T;
    if (S == T) {
        cout << "Yes" << endl;
        return 0;
    }
    if (S.size() < T.size()) {
        swap(S, T);
    }
    HashInterval hs(S), ht(T);
    if (S.size() == T.size()) {
        int N = S.size();
        for (int i = 0; i < S.size(); i++) {
            if (hs.hashInterval(0, i) == ht.hashInterval(0, i) &&
                hs.hashInterval(i + 1, N) == ht.hashInterval(i + 1, N)) {
                    cout << "Yes" << endl;
                    return 0;
                }
        }
    } else {
        if (S.size() > T.size() + 1) {
            cout << "No" << endl;
            return 0;
        }
        for (int i = 0; i < S.size(); i++) {
            if (hs.hashInterval(0, i) == ht.hashInterval(0, i) &&
                hs.hashInterval(i + 1, S.size()) == ht.hashInterval(i, T.size())) {
                    cout << "Yes" << endl;
                    return 0;
                }
        }
    }
    cout << "No" << endl;
    return 0;
}