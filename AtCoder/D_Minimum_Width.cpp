#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int M, N;
    cin >> N >> M;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    ll L = *min_element(A.begin(), A.end()) - 10, R = (ll)1e18;
    while (R - L > 1) {
        ll MID = L + (R - L) / 2;
        ll lines = 1;
        ll length = 0;
        for (int i = 0; i < N; i++) {
            if (A[i] > MID) {
                lines = M + 1;
                break;
            }
            if (length + A[i] > MID) {
                lines++;
                length = A[i] + 1;
            } else {
                length += A[i] + 1;
            }
        }

        if (lines > M) {
            L = MID;
        } else {
            R = MID;
        }
    }
    cout << R << endl;
    return 0;
}