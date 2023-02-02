#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    vector<int> A(N);
    int sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        sum += A[i];
    }
    int ans = 0;
    for (int i = 0; i < N - 1; i++) {
        int current = sum;
        current -= A[i];
        current -= A[i+1];
        current -= A[i];
        current -= A[i+1];
        if (i == 0) ans = current;
        else ans = max(ans, current);
    }
    cout << ans << endl;
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