#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

long long binary(long long base, long long power, ll MOD) {
    long long result = 1;

    while (power > 0) {
        if (power % 2 == 1) {
            result = (result * base) % MOD;
            power--;
        }

        base = (base * base) % MOD;
        power /= 2;
    }

    return result;
}

int main() {
    const int MOD = 998244353;
    int XN;
    cin >> XN;
    vector<int> A(XN), B(XN);
    for (int i = 0; i < XN; i++) cin >> A[i];
    for (int i = 0; i < XN; i++) cin >> B[i];
    int YN;
    cin >> YN;
    vector<int> C(YN), D(YN);
    for (int i = 0; i < YN; i++) cin >> C[i];
    for (int i = 0; i < YN; i++) cin >> D[i];
    map<int, int> p;
    for (int i = 0; i < XN; i++) {
        p[A[i]] = B[i];
    }
    int places = 0;
    bool fail = 0;
    for (int i = 0; i < YN; i++) {
        if (p[C[i]] < D[i]) { fail = 1; break; }
        if (p[C[i]] != D[i]) places++;
        p.erase(C[i]);
    }
    places += p.size();
    if (fail) cout << 0 << endl;
    else cout << binary(2, places, MOD) << endl;
    return 0;
}