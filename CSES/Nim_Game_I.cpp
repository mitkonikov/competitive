#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    int XOR = 0;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        XOR ^= x;
    }
    cout << (XOR == 0 ? "second" : "first") << endl;
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