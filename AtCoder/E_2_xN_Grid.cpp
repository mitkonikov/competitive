#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct event {
    int where;
    ll pos;
    int value;
    ll length;

    bool operator<(const event& other) const {
        if (pos == other.pos) return length > other.length;
        return pos < other.pos;
    }
};

int main() {
    ll L;
    int A, B;
    cin >> L >> A >> B;
    vector<event> events;
    ll p = 1;
    for (int i = 0; i < A; i++) {
        ll v, l;
        cin >> v >> l;
        events.push_back({ 0, p, (int)v, l });
        p += l;
    }
    p = 1;
    for (int i = 0; i < B; i++) {
        ll v, l;
        cin >> v >> l;
        events.push_back({ 1, p, (int)v, l });
        p += l;
    }
    sort(events.begin(), events.end());
    auto match = [&](int a, int b) {
        return (events[a].value == events[b].value);
    };
    ll ans = 0;
    int iA = (events[0].where == 0 ? 0 : 1);
    int iB = (events[0].where == 0 ? 1 : 0);
    auto update = [&]() {
        if (events[iA].length < events[iB].length) {
            events[iB].length -= events[iA].length;
            if (match(iA, iB)) ans += events[iA].length;
            events[iA].length = 0;
        } else {
            events[iA].length -= events[iB].length;
            if (match(iA, iB)) ans += events[iB].length;
            events[iB].length = 0;
        }
    };
    update();
    for (int i = 2; i < events.size(); i++) {
        if (events[i].where == 0) iA = i;
        else iB = i;
        update();
    }
    cout << ans << endl;
    return 0;
}