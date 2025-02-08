#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

const int MX = 1e7 + 100000;

vector<int> lp(MX + 1), pr(MX + 1);

struct Sieve {
    int counter = 0;

    Sieve() {
        for (int i = 0; i < MX; i++) {
            pr[i] = -1;
            lp[i] = 0;
        }

        for (int i = 2; i <= MX; ++i) {
            if (lp[i] == 0) {
                lp[i] = i;
                pr[counter++] = i;
            }
            for (int j = 0; j < counter && pr[j] <= lp[i] && i * pr[j] <= MX;
                 ++j)
                lp[i * pr[j]] = pr[j];
        }
    }
};

map<int, int> mp;

void testCase() {
    int N;
    cin >> N;
    if (N < 5) {
        cout << 0 << endl;
        return;
    }
    auto it = mp.upper_bound(N);
    it--;
    cout << it->second << endl;
}

int main() {
    Sieve s;
    int P = s.counter;
    for (int i = 0; i < P; i++) {
        if (lp[pr[i] - 2] == pr[i] - 2) {
            mp[pr[i]]++;
        }
    }

    int prev = 0;
    for (auto it = mp.begin(); it != mp.end(); it++) {
        prev++;
        it->second = prev;
    }

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cout << "Case #" << (i + 1) << ": ";
        testCase();
    }

    cout << flush;
    return 0;
}