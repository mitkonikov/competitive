#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N, L, R;
    cin >> N >> L >> R;
    L--; R--;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<int> B;
    ll sum = 0;
    for (int i = L; i <= R; i++) {
        B.push_back(A[i]);
        sum += A[i];
    }
    sort(B.rbegin(), B.rend());
    ll ans = sum;
    vector<int> front, back;
    for (int i = 0; i < L; i++) {
        front.push_back(A[i]);
    }
    for (int i = R + 1; i < N; i++) {
        back.push_back(A[i]);
    }
    sort(front.begin(), front.end());
    sort(back.begin(), back.end());
    ll init_sum = sum;
    for (int i = 0; i < min(front.size(), B.size()); i++) {
        sum += front[i] - B[i];
        ans = min(ans, sum);
    }
    sum = init_sum;
    for (int i = 0; i < min(back.size(), B.size()); i++) {
        sum += back[i] - B[i];
        ans = min(ans, sum);
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