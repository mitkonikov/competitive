#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N, Q;
    cin >> N;
    string S;
    cin >> S;
    cin >> Q;
    vector<int> T(N + 1);
    for (int i = 0; i < N; i++) T[i+1] = (S[i] == '1');
    vector<int> A(N + 1);
    for (int i = 0; i < Q; i++) {
        int B;
        cin >> B;
        A[B] ^= 1;
    }
    for (int i = 1; i <= N; i++) {
        if (A[i]) {
            for (int j = i; j <= N; j += i) {
                T[j] ^= 1;
            }
        }
    }
    int press = 0;
    for (int i = 1; i <= N; i++) {
        if (T[i]) {
            press++;
            for (int j = i; j <= N; j += i) {
                T[j] ^= 1;
            }
        }
    }
    cout << press << endl;
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