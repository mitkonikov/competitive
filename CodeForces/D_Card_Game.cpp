#include <bits/stdc++.h>
#define ll long long
// #define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    char T;
    cin >> T;
    vector<string> cards(2 * N);
    for (int i = 0; i < 2 * N; i++) cin >> cards[i];
    vector<vector<int>> played(4);
    auto suit = [](char c) {
        if (c == 'C') return 0;
        if (c == 'D') return 1;
        if (c == 'H') return 2;
        return 3;
    };
    char rsuit[] = { 'C', 'D', 'H', 'S' };
    auto rcard = [](int c) {
        char t = '2' + c;
        return string{ t };
    };
    for (int i = 0; i < 2 * N; i++) played[suit(cards[i][1])].push_back(cards[i][0] - '2');
    for (int s = 0; s < 4; s++) {
        sort(played[s].begin(), played[s].end());
    }
    vector<pair<string, string>> ans;
    for (int s = 0; s < 4; s++) {
        if (s == suit(T)) continue;
        for (int i = 0; i < (int)played[s].size() - 1; i += 2) {
            ans.push_back({ rcard(played[s][i]) + rsuit[s], rcard(played[s][i+1]) + rsuit[s] });
        }
    }
    reverse(played[suit(T)].begin(), played[suit(T)].end());
    for (int s = 0; s < 4; s++) {
        if (s == suit(T)) continue;
        if ((int)played[s].size() % 2 == 1) {
            if (played[suit(T)].empty()) {
                cout << "IMPOSSIBLE" << endl;
                return;
            } else {
                ans.push_back({ rcard(played[s].back()) + rsuit[s], rcard(played[suit(T)].back()) + T });
                played[suit(T)].pop_back();
            }
        }
    }
    if ((int)played[suit(T)].size() % 2 == 1) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    for (int i = 0; i < (int)played[suit(T)].size() - 1; i += 2) {
        ans.push_back({ rcard(played[suit(T)][i + 1]) + T, rcard(played[suit(T)][i]) + T });
    }
    for (auto [u, v]: ans) {
        cout << u << " " << v << endl;
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