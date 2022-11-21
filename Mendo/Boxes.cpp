// Task: https://mendo.mk/Task.do?id=36

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> p(n), k(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> k[i];
    }

    int i = 0, j = 0;
    int count = 0;
    while (i < n && j < m) {
        if (p[i] <= k[j]) {
            count++;
            i++; j++;
        } else {
            j++;
        }
    }

    cout << count << endl;
    return 0;
}