#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    vector<pair<int, int>> A(N);
    vector<int> comp;
    for (int i = 0; i < N; i++) {
        cin >> A[i].first >> A[i].second;
        comp.push_back(A[i].first);
        comp.push_back(A[i].second);
    }
    sort(comp.begin(), comp.end());
    for (int i = 0; i < N; i++) {
        A[i].first = lower_bound(comp.begin(), comp.end(), A[i].first) - comp.begin();
        A[i].second = lower_bound(comp.begin(), comp.end(), A[i].second) - comp.begin();
    }
    sort(A.begin(), A.end());
    vector<int> max_second(N + 1);
    max_second[N-1] = comp[A[N-1].second];
    for (int i = N - 2; i >= 0; i--) {
        max_second[i] = max(max_second[i+1], comp[A[i].second]);
    }
    set<int> prev;
    int ans = INT_MAX;
    for (int i = 0; i < N; i++) {
        if (i - 1 >= 0) {
            prev.insert(A[i-1].second);
        }
        auto it = prev.lower_bound(A[i].first);
        auto it2 = (it == prev.begin() ? prev.end() : std::prev(it));
        int current = INT_MAX;
        if (it != prev.end())  current = min(current, abs(comp[A[i].first] - max(max_second[i+1], comp[*it])));
        if (it2 != prev.end()) current = min(current, abs(comp[A[i].first] - max(max_second[i+1], comp[*it2])));
        if (i != N - 1) current = min(current, abs(comp[A[i].first] - max_second[i+1]));
        ans = min(ans, current);
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