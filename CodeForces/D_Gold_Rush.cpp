#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N, M;
    cin >> N >> M;
    if (M > N) {
        cout << "NO" << endl;
        return;
    }
    if (M == N) {
        cout << "YES" << endl;
        return;
    }
    int n3 = 0, n2 = 0;
    int m3 = 0, m2 = 0;
    while (N % 3 == 0) {
        n3++;
        N /= 3;
    }
    while (N % 2 == 0) {
        n2++;
        N /= 2;
    }
    while (M % 3 == 0) {
        m3++;
        M /= 3;
    }
    while (M % 2 == 0) {
        m2++;
        M /= 2;
    }
    if (N != M || m3 > n3 || m2 < n2) {
        cout << "NO" << endl;
        return;
    }
    int dif = n3 - m3;
    if (dif >= m2 - n2) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    cout << flush;
    return 0;
}