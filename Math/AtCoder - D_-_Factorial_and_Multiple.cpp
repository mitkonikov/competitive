#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

const int N = 1100000;
vector<int> is_prime;

long long binary(long long base, long long power) {
    long long result = 1;

    while (power > 0) {
        if (power % 2 == 1) {
            result = result * base;
            power--;
        }

        base = base * base;
        power /= 2;
    }

    return result;
}

int main() {
    is_prime.resize(N+1, false);
    ll K;
    cin >> K;

    map<ll, int> prime;

    for (ll i = 2; i * i <= K; i++) {
        int count = 0;
        while (K % i == 0) {
            count++;
            K = K / i;
        }
        if (count) prime[i] += count;
    }

    if (K != 1) prime[K]++;

    ll L = 1, R = 1e12 + 1000;
    while (R - L > 1) {
        ll mid = L + (R - L) / 2;
        bool ok = true;
        for (auto factor: prime) {
            ll sum = 0;
            for (int i = 1; ; i++) {
                ll left = mid / binary(factor.first, i);
                if (left == 0) break;
                sum += left;
            }
            if (sum < factor.second) {
                ok = false;
                break;
            }
        }

        if (ok) {
            R = mid;
        } else {
            L = mid + 1;
        }
    }

    for (ll off = max(L - 2, 0LL); off <= L + 2; off++) {
        bool ok = true;
        for (auto factor: prime) {
            ll sum = 0;
            for (int i = 1; ; i++) {
                ll left = off / binary(factor.first, i);
                if (left == 0) break;
                sum += left;
            }
            if (sum < factor.second) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << off << endl;
            return 0;
        }
    }

    cout << L << endl;
    return 0;
}