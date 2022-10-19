#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int n;
    cin >> n;

    vector<int> ans(n);
    ans[0] = 1;
    ans.back() = 2;
    for (int i = 1; i < n - 1; i++) {
        ans[i] = 2 + i;
    }
    for (auto el: ans) {
        cout << el << " ";
    } cout << endl;
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