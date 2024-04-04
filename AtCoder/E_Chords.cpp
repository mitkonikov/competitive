#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> A(N);
    for (int i = 0; i < N; i++) {
        int u, v;
        cin >> u >> v;
        A[i] = { min(u, v), max(u, v) };
    }
    sort(A.begin(), A.end(), [&](auto a, auto b) {
        return a.second < b.second;
    });
    stack<pair<int, int>> intervals;
    for (int i = 0; i < N; i++) {
        auto v = A[i];
        while (intervals.size() > 0) {
            auto t = intervals.top();
            if (t.second > v.first) {
                if (t.first > v.first) {
                    intervals.pop();
                    continue;
                } else {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
            break;
        }
        intervals.push(v);
    }
    cout << "No" << endl;
    return 0;
}