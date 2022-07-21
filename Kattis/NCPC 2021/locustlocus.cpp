#include <bits/stdc++.h>

using namespace std;

int main() {
    int k;
    cin >> k;

    int mn = INT_MAX;
    for (int i = 0; i < k; i++) {
        int start, c1, c2;
        cin >> start >> c1 >> c2;
        
        int x1 = start + c1;
        int x2 = start + c2;
        while (x1 != x2) {
            if (x1 > x2) {
                x2 += c2;
            } else {
                x1 += c1;
            }
        }

        mn = min(mn, x1);
    }

    cout << mn << endl;

    return 0;
}