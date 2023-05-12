#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<ll> mods;
vector<ll> bases;

int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

// PAY ATTENTION TO THE MODULO FUNCTION
inline ll modulo(ll a, ll M) {
	if (a < M) return a;
	return (a % M) + M;
}

ll expo(ll b, ll e, ll m) {
    ll result = 1;
    while (e > 0) {
        if (e % 2 == 1) {
            result = modulo(result * b, m);
            e--;
            continue;
        }

        b = modulo(b * b, m);
        e /= 2;
    }
    return result;
}

// Power tower from B[l]...B[r]
ll tower(int l, int r, int k) {
    if (l > r || k >= (int)mods.size()) return 1;
    ll e = tower(l + 1, r, k + 1);
    ll b = bases[l];
    return expo(b, e, mods[k]);
}

int main() {
    ll N, M;
    cin >> N >> M;
    bases.resize(N);
    mods.push_back(M);
    while (mods.back() != 1) {
        mods.push_back(phi(mods.back()));
    }
    for (int i = 0; i < N; i++) cin >> bases[i];
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int l, r; cin >> l >> r; l--; r--;
        cout << tower(l, r, 0) % M << endl;
    }
    return 0;
}
