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
    sort(A.begin(), A.end());
    ll sum = 0;
    for (int i = 0; i < N; i++) sum += A[i];
    vector<int> B(N, sum / N);
    for (int i = 0; i < sum % N; i++) B[N-1-i]++;
    ll ans = 0;
    for (int i = 0; i < N; i++) ans += abs(A[i] - B[i]);
    cout << ans / 2 << endl;
    return 0;
}