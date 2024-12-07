#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    // Rewrote from https://codeforces.com/blog/entry/136886?#comment-1224481
    // I really like this approach, it's so clean and much better than what I have been trying to do
    int N;
    cin >> N;
    struct Event {
        vector<int> open;
        vector<int> close;
    };
    map<int, Event> events;
    vector<int> l(N), r(N);
    for (int i = 0; i < N; ++i) {
        cin >> l[i] >> r[i];
        events[l[i]].open.push_back(i);
        events[r[i]].close.push_back(i);
    }
    vector<int> ans(N);
    multiset<int> openL, openR;
    for (const auto& [pos, event] : events) {
        for (int i : event.open) {
            openL.insert(l[i]);
            openR.insert(r[i]);
        }
        for (int i : event.open) {
            auto it = openR.lower_bound(r[i]);
            if (it != openR.end() && next(it) != openR.end()) {
                ans[i] += *next(it) - r[i];
            }
        }
        for (int i : event.close) {
            auto it = openL.upper_bound(l[i]);
            if (it != openL.begin() && prev(it) != openL.begin()) {
                ans[i] += l[i] - *prev(prev(it));
            }
        }
        for (int i : event.close) {
            openL.extract(l[i]);
            openR.extract(r[i]);
        }
    }
    for (auto el: ans) cout << el << endl;
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