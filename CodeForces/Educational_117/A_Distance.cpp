#include <bits/stdc++.h>

using namespace std;

void testCase() {
    int x, y;
    cin >> x >> y;

    if ((double)(x+y) / 2 != (x+y)/2) {
        cout << -1 << " " << -1 << endl;
        return;
    }

    int dist = (x+y) / 2;
    for (int i = 0; i <= 50; i++) {
        for (int j = 0; j <= 50; j++) {
            if (dist == abs(i-j) && dist == abs(x-i) + abs(y-j)) {
                cout << i << " " << j << endl;
                return;
            }
        }
    }

    cout << -1 << " " << -1 << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    return 0;
}