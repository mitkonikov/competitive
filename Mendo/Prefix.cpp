// Task: https://mendo.mk/Task.do?id=45

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (n == 1) {
        cout << a[0][0] << endl;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        vector<int> sizes(n, -1);
        for (int j = 0; j < n; j++) {
            if (i == j) continue;

            int k;
            for (k = 0; k < a[i].size(); k++) {
                if (k < a[j].size() && a[i][k] != a[j][k]) break;
            }

            sizes[j] = k + 1;
        }

        sort(sizes.rbegin(), sizes.rend());
        for (int k = 0; k < sizes[0]; k++) {
            cout << a[i][k];
        }
        cout << endl;
    }
    
    return 0;
}