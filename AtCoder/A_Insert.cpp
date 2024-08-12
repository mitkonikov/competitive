#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N, K, X;
    cin >> N >> K >> X;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) {
        cout << A[i] << " ";
        if (i == K - 1) {
            cout << X << " ";
        }
    }
    cout << endl;
    return 0;
}