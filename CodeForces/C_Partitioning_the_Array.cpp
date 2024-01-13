#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

template<typename T>
T gcd(T a, T b) {
    return (a == 0) ? b : gcd(b % a, a);
}

void testCase() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int points = 0;
    auto solve = [&](int div) {
        int GCD = -1;
        for (int i = 0; i < div; i++) {
            for (int j = i; j + div < N; j += div) {
                int a = abs(A[j] - A[j + div]);
                if (a == 0) continue;
                if (GCD == -1) GCD = a;
                else GCD = gcd(GCD, a);
            }
        }
        points += (GCD != 1);
    };
    for (int div = 1; div * div <= N; div++) {
        if (N % div == 0) {
            solve(div);
            if (div * div != N) solve(N / div);
        }
    }
    cout << points << endl;
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
