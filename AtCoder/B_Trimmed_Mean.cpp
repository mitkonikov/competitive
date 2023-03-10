#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(5 * N);
    for (int i = 0; i < 5 * N; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    double sum = 0;
    for (int i = N; i < 4 * N; i++) {
        sum += A[i];
    }
    sum /= 3 * N;
    cout << fixed << setprecision(15) << sum << endl;
    return 0;
}