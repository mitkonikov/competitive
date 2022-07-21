#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    vector<pair<int, int>> scores(n);
    vector<pair<int, int>> a(n), b(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i] = { x, i };
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        b[i] = { x, i };
    }
    for (int i = 0; i < n; i++) {
        scores[i] = { a[i].first + b[i].first, i };
    }
    auto callback = [](const auto &a, const auto &b) {
        if (a.first == b.first) return (a.second < b.second); // index
        return (a.first > b.first);
    };
    vector<bool> visited(n, false);
    sort(scores.begin(), scores.end(), callback);
    sort(a.begin(), a.end(), callback);
    sort(b.begin(), b.end(), callback);
    for (int i = 0; i < x; i++) {
        visited[a[i].second] = true;
    }
    for (int i = 0, c = 0; c < y; c++) {
        while (i < n) {
            if (visited[b[i].second]) {
                i++; continue;
            } else {
                visited[b[i].second] = true;
                break;
            }
        }
    }

    int counter = 0;
    for (int i = 0; i < n; i++) {
        if (counter == z) break;
        if (visited[scores[i].second]) continue;
        counter++;
        visited[scores[i].second] = true;
    }

    for (int i = 0; i < n; i++) {
        if (visited[i]) cout << i + 1 << endl;
    }

    return 0;
}