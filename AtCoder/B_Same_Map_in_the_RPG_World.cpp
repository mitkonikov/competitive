#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }
    for (int s = 0; s < N; s++) {
        for (int t = 0; t < M; t++) {
            bool ok = true;
            for (int i = 0; i < N && ok; i++) {
                for (int j = 0; j < M && ok; j++) {
                    if (A[(i+s)%N][(j+t)%M] != B[i][j]) {
                        ok = false;
                    }
                }
            }

            if (ok) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}