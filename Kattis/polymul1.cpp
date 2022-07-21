#include <bits/stdc++.h>

using namespace std;

void testCase() {
    int n, m;
    cin >> n;
    n++;

    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cin >> m;
    m++;
    int b[m];
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    const int size = n + m - 1;
    int result[size];
    memset(result, 0, size * sizeof(int));

    for (int i = n-1; i >= 0; i--) {
        for (int j = m-1; j >= 0; j--) {
            int di = n-1 - i;
            int dj = m-1 - j;
            int r = di + dj;
            int ri = size - r - 1;
            result[ri] += (a[i] * b[j]);
        }
    }

    cout << size - 1 << endl;
    for (int i = 0; i < size; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    return 0;
}