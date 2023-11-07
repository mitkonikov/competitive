#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N - 1; i++) {
        cin >> A[i+1];
        A[i+1] ^= A[i];
    }
    for (int l = 0; l < 30; l++) {
        int count = 0;
        for (int i = 0; i < N; i++) {
            count += (bool)(A[i] & (1 << l));
        }
        if (count > N / 2) {
            for (int i = 0; i < N; i++) A[i] ^= (1 << l);
        }
    }
    for (auto el: A) cout << el << " ";
    cout << endl;
    return 0;
}