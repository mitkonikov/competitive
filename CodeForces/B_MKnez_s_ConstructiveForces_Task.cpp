#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    if (N % 2 == 1) {
        if (N == 3) {
            cout << "NO" << endl;
            return;
        }
        cout << "YES" << endl;
        int diff = (N - 2);
        int low = -diff / 2;
        int high = diff / 2 + 1;
        for (int i = 0; i < N; i++) {
            cout << (i % 2 == 0 ? low : high) << " ";
        }
        cout << endl;
        return;
    }
    cout << "YES" << endl;
    for (int i = 0; i < N; i++) {
        cout << (i % 2 == 0 ? 1 : -1) << " ";
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