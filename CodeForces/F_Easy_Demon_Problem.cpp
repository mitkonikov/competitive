#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    const int MX = 4e5 + 100;
    const int OF = 2e5 + 50;
    cin.tie(0)->sync_with_stdio(0);
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<int> A(N), B(M);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < M; i++) cin >> B[i];
    ll sumA = 0, sumB = 0;
    for (int i = 0; i < N; i++) sumA += A[i];
    for (int i = 0; i < M; i++) sumB += B[i];
    vector<bool> seenA(MX), seenB(MX);
    for (int i = 0; i < N; i++) {
        const ll compliment = (ll)OF + sumA - A[i];
        if (compliment >= 0 && compliment < MX) {
            seenA[compliment] = true;
        }
    }
    for (int i = 0; i < M; i++) {
        const ll compliment = (ll)OF + sumB - B[i];
        if (compliment >= 0 && compliment < MX) {
            seenB[compliment] = true;
        }
    }
    for (int i = 0; i < Q; i++) {
        int X;
        cin >> X;
        if (X == 0) {
            cout << ((seenA[OF] || seenB[OF]) ? "YES" : "NO") << endl;
            continue;
        }
        const int absX = abs(X);
        bool ok = false;
        for (int j = 1; j * j <= absX && !ok; j++) {
            if (absX % j == 0) {
                int div1 = j;
                int div2 = absX / j;
                if (X == absX) {
                    for (auto s1 : { -1, 1 }) {
                        for (auto s2 : { -1, 1 }) {
                            if (s1 != s2) continue;
                            ok |= (seenA[OF+div1 * s1] && seenB[OF+div2 * s2]);
                            ok |= (seenA[OF+div2 * s1] && seenB[OF+div1 * s2]);
                        }
                    }
                } else {
                    for (auto s1 : { -1, 1 }) {
                        for (auto s2 : { -1, 1 }) {
                            if (s1 == s2) continue;
                            ok |= (seenA[OF+div1 * s1] && seenB[OF+div2 * s2]);
                            ok |= (seenA[OF+div2 * s1] && seenB[OF+div1 * s2]);
                        }
                    }
                }
            }
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}