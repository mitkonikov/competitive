#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int mnx = INT_MAX, mny = INT_MAX;
    int mxx = INT_MIN, mxy = INT_MIN;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (A[i][j] == '#') {
                mnx = min(mnx, i);
                mxx = max(mxx, i);
                mny = min(mny, j);
                mxy = max(mxy, j);
            }
        }
    }
    for (int i = mnx; i <= mxx; i++) {
        for (int j = mny; j <= mxy; j++) {
            if (A[i][j] != '#') {
                cout << i + 1 << " " << j + 1 << endl;
                return 0;
            }
        }
    }
    return 0;
}