#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    vector<int> A(N);
    bool all_even = 1;
    int even = 0, odd = 0;
    vector<int> evenN, oddN;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (A[i] % 2 == 1) {
            all_even = false;
            odd++;
            oddN.push_back(i+1);
        } else {
            even++;
            evenN.push_back(i+1);
        }
    }
    if (all_even) {
        cout << "NO" << endl;
        return;
    }
    if (N == 3) {
        if (even == 1 && odd == 2) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    if (oddN.size() >= 3) {
        for (int i = 0; i < 3; i++) {
            cout << oddN[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < 2; i++) {
        cout << evenN[i] << " ";
    }
    cout << oddN[0] << endl;
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