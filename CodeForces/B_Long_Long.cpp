#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int count = 0;
    ll ans = 0;
    bool neg = 0;
    A.push_back(1);
    for (int i = 0; i < N + 1; i++) {
        ans += abs(A[i]);
        if (A[i] > 0) {
            if (neg) {
                count++;
            }
            neg = 0;
        } else {
            if (A[i] < 0 && !neg) {
                neg = 1;
            }
        }
    }
    cout << ans - 1 << " " << count << endl;
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