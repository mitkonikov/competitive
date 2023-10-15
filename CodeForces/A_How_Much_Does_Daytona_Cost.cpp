#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        int most_common = -1;
        int most_frq = -1;
        vector<int> frq(110);
        for (int j = i; j < N; j++) {
            frq[A[j]]++;
            if (frq[A[j]] > most_frq) {
                most_frq = frq[A[j]];
                most_common = A[j];
            }
            if (most_common == K) {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
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