#include <bits/stdc++.h>

using namespace std;

int pre_xor[300005];

void testCase() {
    int a, b;
    cin >> a >> b;

    int ans = a;
    int XOR = pre_xor[a-1] ^ b;

    if (XOR == 0) {
        cout << ans << endl;
        return;
    }

    if (XOR < a) {
        cout << ans + 1 << endl;
    } else if (XOR == a) {
        cout << ans + 2 << endl;
    } else {
        cout << ans + 1 << endl;
    }
}

int main() {
    pre_xor[0] = 0;
    for (int i = 1; i < 300005; i++) {
        pre_xor[i] = pre_xor[i - 1] ^ i;
    }

    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    return 0;
}