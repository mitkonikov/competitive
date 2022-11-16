#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int n, m;
    cin >> n >> m;
    int sum = n + m;
    for (int i = 2; i < sum; i++) {
        if (sum % i == 0) {
            cout << "Bob" << endl;
            return;
        }
    }
    cout << "Alice" << endl;
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