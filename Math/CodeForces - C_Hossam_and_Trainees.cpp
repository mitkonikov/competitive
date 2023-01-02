#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct Sieve {
    static const int N = 1e5 + 10;
    int lp[N + 1], pr[N + 1];
    int counter = 0;
    vector<int> primes;

    Sieve() {
        for (int i = 0; i < N; i++) {
            pr[i] = -1;
            lp[i] = 0;
        }

        for (int i = 2; i <= N; ++i) {
            if (lp[i] == 0) {
                lp[i] = i;
                pr[counter++] = i;
                primes.push_back(i);
            }
            for (int j = 0; j < counter && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
                lp[i * pr[j]] = pr[j];
        }
    }
};

void testCase(Sieve* s) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<int> primes;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < s->primes.size(); j++) {
            if (a[i] % s->primes[j] == 0) {
                primes.push_back(s->primes[j]);
                while (a[i] % s->primes[j] == 0) a[i] /= s->primes[j];
            }
        }
        if (a[i] > 1) primes.push_back(a[i]);
    }
    
    sort(primes.begin(), primes.end());
    for (int i = 1; i < primes.size(); i++) {
        if (primes[i] == primes[i-1]) {
            cout << "YES" << endl;
            return;
        }
    }

    cout << "NO" << endl;
}

int main() {
    Sieve* s = new Sieve();
    
    int t;
    cin >> t;

    while (t--) {
        testCase(s);
    }

    return 0;
}