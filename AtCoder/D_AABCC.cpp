#include <bits/stdc++.h>
#define ll long long
#define ll128 __int128_t

using namespace std;

struct Sieve {
    static const int N = 1e6 + 1000;
    int lp[N + 1], pr[N + 1];
    int counter = 0;

    Sieve() {
        for (int i = 0; i < N; i++) {
            pr[i] = -1;
            lp[i] = 0;
        }

        for (int i = 2; i <= N; ++i) {
            if (lp[i] == 0) {
                lp[i] = i;
                pr[counter++] = i;
            }
            for (int j = 0; j < counter && pr[j] <= lp[i] && i * pr[j] <= N;
                 ++j)
                lp[i * pr[j]] = pr[j];
        }
    }
};

Sieve s;

int main() {
    ll N;
    cin >> N;

    int count = 0;
    for (int i = 0; i < s.counter; i++) {
        ll128 a2 = (ll)s.pr[i] * s.pr[i];
        if (a2 > N) break;

        for (int j = i + 1; j < s.counter; j++) {
            ll128 a2b = a2 * s.pr[j];
            if (a2b > N) {
                break;
            }

            for (int k = j + 1; k < s.counter; k++) {
                if (a2b * s.pr[k] * s.pr[k] > N) break;
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}