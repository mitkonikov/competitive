#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        int y;
        cin >> y;
        if (y == x) {
            cout << i + 1 << endl;
        }
    }
    return 0;
}