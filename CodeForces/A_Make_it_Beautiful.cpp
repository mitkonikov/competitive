#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    if (a[0] == a.back()) {
        cout << "NO" << endl;
        return;
    }
    reverse(a.begin(), a.end());
    if (a[0] == a[1]) {
        //  4 1 4 4
        for (int i = 0; i < N; i++) {
            if (a[i] != a[0]) {
                swap(a[1], a[i]);
                break;
            }
        }
    }
    cout << "YES" << endl;
    for (auto el: a) {
        cout << el << " ";
    }
    cout << endl;
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