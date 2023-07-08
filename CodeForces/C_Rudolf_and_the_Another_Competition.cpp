#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N, M, H;
    cin >> N >> M >> H;
    vector<pair<ll, ll>> P(N);
    for (int i = 0; i < N; i++) {
        vector<int> A(M);
        for (int j = 0; j < M; j++) {
            cin >> A[j];
        }
        sort(A.begin(), A.end());
        ll sum = 0;
        ll time = 0;
        int problems = 0;
        for (int j = 0; j < M; j++) {
            if (time + A[j] > H) break;
            time += A[j];
            sum += time;
            problems++;
        }
        P[i] = { -problems, sum };
    }
    vector<int> order(N);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int a, int b) {
        if (P[a] == P[b]) return a < b;
        return P[a] < P[b];
    });
    for (int i = 0; i < N; i++) {
        if (order[i] == 0) {
            cout << i + 1 << endl;
            return;
        }
    }
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