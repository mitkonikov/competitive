#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int A;
ll X, Y;

map<ll, double> dp;

double E(ll N) {
    if (N == 0) return 0;
    auto it = dp.find(N);
    if (it != dp.end()) {
        return it->second;
    }

    double result = LLONG_MAX;
    
    double sum = 0;
    for (int b = 6; b >= 2; b--) {
        sum += E(N / b);
    }

    double inter = (sum / 6 + Y) / ((double)5 / 6);
    result = min(inter, A != 1 ? (E(N / A) + X) : LLONG_MAX);

    return dp[N] = result;
}

int main() {
    ll N;
    cin >> N >> A >> X >> Y;
    cout << fixed << setprecision(16) << E(N) << endl;
    return 0;
}