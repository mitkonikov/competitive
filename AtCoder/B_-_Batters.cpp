#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(4, 0);
    int p = 0;
    for (int i = 0; i < n; i++) {
        a[0]++;
        int x;
        cin >> x;
        for (int j = 3; j >= 0; j--) {
            if (j + x >= 4) {
                p += a[j];
                a[j] = 0;
            } else {
                a[j+x] += a[j];
                a[j] = 0;
            }
        }
    }
    cout << p << endl;
    cout << flush;
    return 0;
}