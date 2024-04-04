#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());
    int p = 0;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        while (p < A.size() && A[p] - A[i] < M) {
            p++;
        }

        ans = max(ans, p - i);
    }
    cout << ans << endl;
    return 0;
}