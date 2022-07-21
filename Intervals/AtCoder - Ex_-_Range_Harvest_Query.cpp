#include <bits/stdc++.h>
// #include "atcoder/modint.hpp"
#define ll long long
#define endl '\n'
#define pii pair<ll, ll>

using namespace std;

ll mod = 998244353;
struct mint {
    int value;

    mint(long long x = 0) { value = normalize(x); }

    int normalize(long long x) {
        if (x < -mod || x >= mod)
            x %= mod;
        if (x < 0)
            x += mod;
        return static_cast<int>(x);
    }

    explicit operator int() const { return value; }

    mint operator-() const { return mint(-value); }

    mint &operator+=(mint rhs) {
        if ((value += rhs.value) >= mod)
            value -= mod;
        return *this;
    }

    mint &operator-=(mint rhs) {
        if ((value -= rhs.value) < 0)
            value += mod;
        return *this;
    }

    mint &operator*=(mint rhs) {
        value = normalize(static_cast<long long>(value) * rhs.value);
        return *this;
    }

    mint &operator/=(mint rhs) { return *this *= mint(inverse(rhs.value, mod)); }

    int inverse(int a, int m) {
        int u = 0, v = 1;
        while (a != 0) {
            int t = m / a;
            m -= t * a;
            swap(a, m);
            u -= t * v;
            swap(u, v);
        }
        assert(m == 1);
        return u;
    }

    bool operator==(mint rhs) const { return value == rhs.value; }

    bool operator!=(mint rhs) const { return !(*this == rhs); }

    friend mint operator+(mint lhs, mint rhs) { return lhs += rhs; }

    friend mint operator-(mint lhs, mint rhs) { return lhs -= rhs; }

    friend mint operator*(mint lhs, mint rhs) { return lhs *= rhs; }

    friend mint operator/(mint lhs, mint rhs) { return lhs /= rhs; }
};

struct interval {
    pii range;
    ll day;

    bool operator<(const interval &other) const {
        return this->range < other.range;
    }
};

struct cmp {
    bool operator()(const interval &t, const interval &other) const {
        return t.range < other.range;
    }
};

mint harvest = 0;

mint calc(ll L, ll R, mint dayNow, mint dayPrev) {
    if (L > R) return (mint)0;
    ll Rm = (R - 1);
    ll Lm = (L - 1);
    if (R % 2 == 0) R /= 2;
    else if (Rm % 2 == 0) Rm /= 2;
    if (L % 2 == 0) L /= 2;
    else if (Lm % 2 == 0) Lm /= 2;
    
    mint Rs = (mint)R * (mint)Rm;
    mint Ls = (mint)L * (mint)Lm;
    return (Rs - Ls) * (dayNow - dayPrev);
}

set<interval, cmp> sets;
void removeInterval(ll L, ll R, ll currentDay) {
    if (L == R) return;
	auto it = sets.lower_bound(interval{ pii{L, 0}, -1 });
    it--;
    // L and R should not be changed
    ll left_day = it->day, right_day = it->day;
    ll curL = it->range.first;
    ll curR = it->range.second;
    while (it != sets.end() && it->range.first < R) {
        right_day = it->day;
        harvest += calc(max(L, it->range.first), min(R, it->range.second), currentDay, it->day);
        curR = max(curR, it->range.second);
        it = sets.erase(it);
    }
    if (curL != L) sets.insert({{curL, L}, left_day});
    if (curR != R) sets.insert({{R, curR}, right_day});
}

int main() {
    ll N;
    int Q;
    cin >> N >> Q;
    sets.insert({ {0, LLONG_MAX - 10}, 0 });
    for (int i = 0; i < Q; i++) {
        ll day, l, r;
        cin >> day >> l >> r;
        harvest = 0;
        removeInterval(l, r+1, day);
        sets.insert({ {l, r+1}, day });
        cout << harvest.value << endl;
    }
    ll prev = 0;
    for (auto s: sets) {
        if (s.range.first != prev) assert(false);
        prev = s.range.second;
    }
    cout << flush;
    return 0;
}