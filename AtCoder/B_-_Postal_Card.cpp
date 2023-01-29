#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int ans = 0;
    vector<string> A(N), B(M);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < M; i++) cin >> B[i];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (A[i].substr(3) == B[j]) {
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}