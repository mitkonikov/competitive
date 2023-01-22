#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int N, X;
    cin >> N >> X;
    vector<bool> can(X + 10, false);
    can[0] = true;
    for (int i = 0; i < N; i++) {
        int A, B;
        cin >> A >> B;
        for (int c = X; c >= 0; c--) {
            if (!can[c]) continue;
            int p = c + A;
            for (int j = 0; j < B; j++) {
                if (p > X) break;
                can[p] = true;
                p += A;
            }
        }
    }
    cout << endl;
    cout << (can[X] ? "Yes" : "No") << endl;
    return 0;
}