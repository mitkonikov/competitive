#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    ll N, A, B;
    cin >> N >> A >> B;

    if (A == 1) {
        cout << N << endl;
        return 0;
    }

    if (A > N) {
        cout << 0 << endl;
        return 0;
    }

    if (A <= B) {
        cout << N - (A - 1) << endl;
        return 0;
    }

    cout << (N / A - 1) * B + min(N % A + 1, B) << endl;

    cout << flush;
    return 0;
}