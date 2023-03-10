#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int curr = 0;
    int used = 0;
    int unknown = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] == 1) {
            unknown++;
            if (curr - used == 0) {
                curr++;
                used++;
            } else {
                used++;
            }
        } else {
            if (!unknown) continue;
            if (unknown % 2 == 1) {
                used -= unknown / 2;
                unknown = 1;
            } else {
                used -= (unknown-2) / 2;
                unknown = 2;
            }
        }
    }
    cout << curr << endl;
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