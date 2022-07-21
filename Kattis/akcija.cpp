#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.rbegin(), arr.rend());

    long long result = 0;
    for (int i = 0; i < n; i += 3) {
        if (i + 2 < n) {
            result = result + arr[i] + arr[i+1];
        } else {
            result = result + arr[i];
            if (i+1 < n) result = result + arr[i+1];
        }
    }

    cout << result << endl;

    return 0;
}