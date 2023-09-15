#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int mx = -1;
    for (int i = 1; i < N; i++) {
        mx = max(mx, A[i]);
    }
    if (mx < A[0]) {
        cout << 0 << endl;
        return 0;
    }
    cout << mx - A[0] + 1 << endl;
    return 0;
}