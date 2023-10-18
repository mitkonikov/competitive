#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    if (N == 5) {
        double ans = 0;
        {
            double dist1 = (double)(A[2] - A[0]) / 2;
            double distN = (double)(A[N-1] - A[N-2]) / 2;
            ans = max(ans, A[N-1] - distN - (A[0] + dist1));
        }
        {
            double dist1 = (double)(A[1] - A[0]) / 2;
            double distN = (double)(A[N-1] - A[N-3]) / 2;
            ans = max(ans, A[N-1] - distN - (A[0] + dist1));
        }
        if ((ll)round(ans) == (ll)ans) cout << (ll)ans << endl;
        else cout << (ll)floor(ans) << ".5" << endl;
    } else {
        double dist1 = (double)(A[1] - A[0]) / 2;
        double distN = (double)(A[N-1] - A[N-2]) / 2;
        double ans = A[N-1] - distN - (A[0] + dist1);
        if ((ll)round(ans) == (ll)ans) cout << (ll)ans << endl;
        else cout << (ll)floor(ans) << ".5" << endl;
    }
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cout << "Case #" << i + 1 << ": ";
        testCase();
    }

    cout << flush;
    return 0;
}