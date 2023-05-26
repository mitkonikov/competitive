#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    if (N % 2 == 1) {
        cout << -1 << endl;
        return;
    }
    for (int i = N - 1; i >= 0; i--) {
        cout << i + 1 << " ";
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