#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    string S;
    cin >> S;
    vector<pair<char, int>> lower, upper;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == 'b') {
            if (!lower.empty()) lower.pop_back();
        } else if (S[i] == 'B') {
            if (!upper.empty()) upper.pop_back();
        } else {
            if (S[i] >= 'A' && S[i] <= 'Z') upper.push_back({ S[i], i });
            else lower.push_back({ S[i], i });
        }
    }
    string ans = "";
    int p1 = 0, p2 = 0;
    while (p1 < lower.size() || p2 < upper.size()) {
        if (p1 < lower.size() && p2 < upper.size()) {
            if (lower[p1].second < upper[p2].second) {
                ans += lower[p1].first;
                p1++;
            } else {
                ans += upper[p2].first;
                p2++;
            }
        } else if (p1 < lower.size()) {
            ans += lower[p1].first;
            p1++;
        } else {
            ans += upper[p2].first;
            p2++;
        }
    }
    cout << ans << endl;
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