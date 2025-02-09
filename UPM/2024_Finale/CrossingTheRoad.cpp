#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
const ll CAR_LENGTH = 5'000'000'000;
const ll USER_TIME_PER_ROAD = 1'440'000'000'000;
const ll CAR_DIALATION = 8'000'000'000;
 
int main() {
    ll L, R;
    cin >> L >> R;
    ll N = L + R;
    ll result = (ll)N * USER_TIME_PER_ROAD;
    vector<vector<pair<ll, ll>>> roads(N);
    vector<pair<ll, ll>> intervals;
    for (ll i = 0; i < N; i++) {
        ll K;
        cin >> K;
        roads[i].resize(K);
        for (ll k = 0; k < K; k++) {
            ll start;
            cin >> start;
 
            ll OFFSET = i * CAR_DIALATION;
            roads[i][k] = make_pair(start - CAR_DIALATION - OFFSET, start + CAR_LENGTH - OFFSET);
 
            if (roads[i][k].second >= 0) {
                intervals.push_back(roads[i][k]);
            }
        }
    }
    std::sort(intervals.begin(), intervals.end(), [&](auto a, auto b) {
        if (a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    });
 
    if (intervals.empty() || intervals[0].first >= 0) {
        cout << result << endl;
        return 0;
    }
 
    for (ll i = 1; i < intervals.size(); i++) {
        if (intervals[i].first >= intervals[i-1].second) {
            cout << intervals[i-1].second * 180 + result << endl;
            return 0;
        }
    }
    cout << intervals.back().second * 180 + result << endl;
    return 0;
}