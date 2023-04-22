#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N, T;
    cin >> N >> T;
    vector<int> C(N), R(N);
    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> R[i];
    }
    bool ok = false;
    for (int i = 0; i < N; i++) {
        if (C[i] == T) {
            ok = true;
        }
    }
    if (!ok) T = C[0];
    int r = -1;
    int w = -1;
    for (int i = 0; i < N; i++) {
        if (C[i] == T) {
            if (R[i] >= r) {
                r = R[i];
                w = i;
            }
        }
    }
    cout << w + 1 << endl;
    return 0;
}