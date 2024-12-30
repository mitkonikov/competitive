#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> black, white;
    map<int, int> max_col;
    for (int i = 0; i < M; i++) {
        int X, Y;
        char C;
        cin >> X >> Y >> C;
        if (C == 'B') {
            black.push_back({ X, Y });
            max_col[Y] = max(max_col[Y], X);
        } else {
            white.push_back({ X, Y });
        }
    }
    for (auto it = max_col.begin(); it != max_col.end(); it++) {
        while (it != max_col.begin() && prev(it)->second <= it->second) {
            max_col.erase(prev(it));
        }
    }
    sort(white.begin(), white.end(), [](auto a, auto b) {
        if (a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    });
    int ptr = 0;
    set<int> active;
    for (auto [c, r] : max_col) {
        while (ptr < white.size() && white[ptr].second <= c) {
            active.insert(white[ptr].first);
            ptr++;
        }
        // see if theres a white cell (x, y) where x <= r && y <= c
        if (!active.empty() && *active.begin() <= r) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}