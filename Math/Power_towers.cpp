#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

#define MAX 1100000

int phi[MAX];
int lp[MAX];
int pr[MAX];
bool is_prime[MAX];

void totient() {
    for (int i = 0; i < MAX; i++) {
        phi[i] = i;
        is_prime[i] = true;
        lp[i] = 0;
        pr[i] = -1;
    }
    int counter = 0;
    for (int i = 2; i < MAX; i++) {
        if (is_prime[i]) {
            for (int j = i; j < MAX; j += i) {
                is_prime[j] = false;
                phi[j] = phi[j] - (phi[j] / i);
            }
            lp[i] = i;
            pr[counter++] = i;
        }
        
        for (int j = 0; j < counter && pr[j] <= lp[i] && i * pr[j] < MAX; ++j)
            lp[i * pr[j]] = pr[j];
    }
}

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

ll tower(vector<int>& bases, int l, int mod) {
    if (mod == 1 || l >= bases.size()) return 1;
    ll e = tower(bases, l + 1, phi[mod]);
    ll b = bases[l];
    return expo(b, e, mod);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    totient();

    int Q, M;
    cin >> Q >> M;

    for (int i = 0; i < Q; i++) {
        int K;
        cin >> K;
        vector<int> t(K);
        for (int k = 0; k < K; k++) {
            cin >> t[k];
        }
        cout << tower(t, 0, M) % M << endl;
    }

    return 0;
}