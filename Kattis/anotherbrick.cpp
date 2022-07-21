#include <bits/stdc++.h>

using namespace std;

int main() {
    int h, w, n;
    cin >> h >> w >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int sum = 0;
    bool complete = true;

    int bh = 0;
    for (int i = 0; bh < h && i < n; i++) {
        sum += arr[i];
        if (sum == w) {
            bh++;
            sum = 0;
        } else if (sum > w) {
            complete = false;
            break;
        }
    }

    if (complete && bh == h) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}