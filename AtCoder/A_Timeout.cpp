#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N, S;
    cin >> N >> S;
    vector<int> A(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    bool ok = true;
    for (int i = 0; i < N; i++) {
        if (A[i+1] - A[i] > S) ok = false;
    }
    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}