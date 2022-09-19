#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int n;
    cin >> n;
    vector<int> ans;
    vector<bool> used(10, false);
    while (n != 0) {
        for (int i = 9; i >= 0; i--) {
            if (used[i]) continue;
            if (n >= i) {
                n -= i;
                ans.push_back(i);
                used[i] = true;
                break;
            }
        }
    }
    sort(ans.begin(), ans.end());
    for (auto el: ans) cout << el;
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