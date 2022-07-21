#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    for (int j = 0; j < 26; j++) {
        for (int i = 0; i < n; i++) {
            if (x == 1) {
                cout << (char)('A' + j) << endl;
                return 0;
            }
            x--;
        }
    }
    cout << flush;
    return 0;
}