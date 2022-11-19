// Task: https://mendo.mk/Task.do?id=115

#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct show {
    int start, end;

    bool operator<(const show& other) const {
        if (end == other.end) return (start < other.start);
        return (end < other.end);
    }

    int range() {
        if (end > start) return end - start;
        if (end == start) return 1440;
        if (end < start) return 1440 - (start - end + 1) + 1;
        return 0;
    }

    bool ok() {
        return (start < end);
    }
};

inline bool umax(int& a, int b) {
    if (b > a) { a = b; return true; }
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<show> a(n);
    bool atLeastOne = false;
    for (int i = 0; i < n; i++) {
        int hs, ms, he, me;
        cin >> hs >> ms >> he >> me;
        int start = hs * 60 + ms + 1;
        int end   = he * 60 + me + 1;
        a[i] = { start, end };
        if (a[i].ok()) atLeastOne = true;
    }
    sort(a.begin(), a.end());
    int ans = 0;
    auto update = [&](int midnight, int minutes) {
        vector<int> dp(1500, 0);
        umax(ans, minutes);
        for (int i = 0; i < n; i++) {
            if (i == midnight) continue;
            if (!a[i].ok()) continue;
            if (midnight != -1 && a[i].start <= a[midnight].end) {
                // can't use it
                continue;
            }
            if (midnight != -1 && a[i].end >= a[midnight].start) {
                continue;
            }

            
            int earliest_possible_start = 0;
            if (midnight != -1) earliest_possible_start = a[midnight].end;
            for (int j = earliest_possible_start; j < a[i].start; j++) {
                umax(dp[a[i].end], dp[j] + a[i].range());
                umax(ans, dp[a[i].end] + minutes);
            }
        }
    };

    if (atLeastOne) update(-1, 0);
    for (int midnight = 0; midnight < n; midnight++) {
        // Observation: Only one show goes over the midnight point
        // If the show starts before it ends, then we can't use it.
        if (a[midnight].ok()) continue;
        update(midnight, a[midnight].range());
    }

    cout << ans << endl;
    return 0;
}