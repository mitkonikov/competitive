#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    map<int, int> mp;
    for (int i = 0; i < N; i++) {
        mp[A[i]]++;
    }
    int twice = 0;
    for (auto [k, v] : mp) {
        if (v >= 2) {
            twice++;
        }
    }
    int once = mp.size() - twice;
    if (once % 2 == 0) {
        cout << (once / 2) * 2 + twice << endl;
    } else {
        cout << ((once + 1) / 2) * 2 + twice << endl;
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