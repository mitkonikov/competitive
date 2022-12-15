#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> events;
    set<int> beacons_there;
    const ll SY = 2000000;
    for (int i = 0; i < N; i++) {
        ll X, Y, A, B;
        cin >> X >> Y >> A >> B;
        if (B == SY) beacons_there.insert(A);
        ll man = abs(A - X) + abs(B - Y) + 1;
        if (abs(Y - SY) > man) continue;
        man -= abs(Y - SY) + 1;
        if (X - man <= X + man) events.push_back({ X - man, X + man });
    } 
    sort(events.begin(), events.end(), [](const auto& a, const auto& b) {
        if (a.second == b.second) return (a.first < b.first);
        return (a.second < b.second);
    });
    vector<pair<int, int>> intervals;
    intervals.push_back(events[0]);
    for (int i = 1; i < events.size(); i++) {
        while (intervals.size() && events[i].first < intervals.back().first) {
            intervals.pop_back();
        }
        if (intervals.size() && events[i].first <= intervals.back().second) {
            intervals.back().second = max(intervals.back().second, events[i].second);
        } else {
            intervals.push_back(events[i]);
        }
    }
    ll ans = 0;
    for (int i = 0; i < intervals.size(); i++) {
        ans += intervals[i].second - intervals[i].first + 1;
        for (auto el: beacons_there) {
            if (el >= intervals[i].first && el <= intervals[i].second) ans--;
        }
    }
    cout << ans << endl;
    return 0;
}