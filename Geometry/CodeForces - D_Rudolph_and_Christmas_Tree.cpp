#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    ll N, D, H;
    cin >> N >> D >> H;
    vector<ll> Y(N);
    for (int i = 0; i < N; i++) cin >> Y[i];
    long double area = 0;
    Y.push_back(Y.back() + H);
    for (int i = 0; i < N; i++) {
        long double intersection = (long double)D * (H - min(H, (Y[i+1] - Y[i]))) / H;
        area += ((long double)D + intersection) * min(H, (Y[i+1] - Y[i])) / 2;
    }
    cout << fixed << setprecision(10) << area << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    cout << flush;
    return 0;
}