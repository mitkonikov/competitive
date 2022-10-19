#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int n;
    cin >> n;
    char c;
    cin >> c;
    string s;
    cin >> s;
    s += s;
    int seen = -1;
    vector<int> green(s.size(), -1);
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == 'g') {
            seen = i;
        }
        green[i] = seen;
    }

    int best = INT_MIN;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == c) {
            if (green[i] == -1) continue;
            best = max(best, green[i] - i);
        }
    }
    cout << (best == INT_MIN ? 0 : best) << endl;
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