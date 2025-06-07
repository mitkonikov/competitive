#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    set<int> A, B;
    for (int i = 0; i < N; i++) {
        int X;
        cin >> X;
        A.insert(X);
    }
    for (int i = 0; i < N; i++) {
        int Y;
        cin >> Y;
        B.insert(Y);
    }
    if ((ll)A.size() * B.size() >= 3) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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