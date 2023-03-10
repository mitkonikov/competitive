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
    vector<int> B(A);
    sort(B.rbegin(), B.rend());
    // max
    int curr = 0;
    vector<int> pos;
    for (int i = 0; i < N; i++) {
        if (B[i] > 0) curr++;
        else curr--;
        cout << curr << " ";
        if (B[i] > 0) pos.push_back(1);
    }
    cout << endl;
    reverse(B.begin(), B.end());
    for (int i = 0; i < N; i++) {
        if (B[i] < 0) {
            cout << "1 0" << " ";
            pos.pop_back();
        }
    }
    curr = 0;
    for (auto el: pos) {
        curr++;
        cout << curr << " ";
    }
    cout << endl;
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