#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N, D;
    cin >> N >> D;
    vector<string> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    string merge = A[0];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < D; j++) {
            if (A[i][j] == 'x') merge[j] = 'x';
        }
    }
    int ans = 0;
    for (int i = 0; i < D; i++) {
        for (int j = i; j < D; j++) {
            if (merge[j] == 'x') {
                break;
            }
            ans = max(ans, j - i + 1);
        }
    }
    cout << ans << endl;
    return 0;
}