#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> frq(200);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        frq[A[i]]++;
    }
    if (frq[0] == N) {
        cout << 0 << endl;
        return;
    }
    if (frq[0] > 0) {
        while (A.size() && A.back() == 0) {
            A.pop_back();
        }
        reverse(A.begin(), A.end());
        while (A.size() && A.back() == 0) {
            A.pop_back();
        }
        for (int i = 0; i < A.size(); i++) {
            if (A[i] == 0) {
                cout << 2 << endl;
                return;
            }
        }
        cout << 1 << endl;
    } else {
        cout << 1 << endl;
    }
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