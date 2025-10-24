#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    int p1 = 0, p2 = N - 1;
    vector<int> ans(N);
    for (int i = 0; i < N; i++) {
        ans[(i % 2 == 0 ? p1 : p2)] = i + 1;
        if (i % 2 == 0) p1++; else p2--;
    }
    for (int i = 0; i < N; i++) cout << ans[i] << " ";
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