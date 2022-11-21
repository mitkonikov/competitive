// Task: https://mendo.mk/Task.do?id=365

#include <bits/stdc++.h>

using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    cout << min(W, H) * 2 - 1 - (H >= W) << endl;
    return 0;
}