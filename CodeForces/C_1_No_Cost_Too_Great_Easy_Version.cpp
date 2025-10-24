#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

const int MX = 2e5 + 1000;
int lp[MX + 1], pr[MX + 1];
 
struct Sieve  {
    int counter = 0;
 
    Sieve() {
        for (int i = 0; i < MX; i++) {
            pr[i] = -1;
            lp[i] = 0;
        }
 
        for (int i = 2; i <= MX; i++) {
            if (lp[i] == 0) {
                lp[i] = i;
                pr[counter++] = i;
            }
            for (int j = 0; j < counter && pr[j] <= lp[i] && i * pr[j] <= MX; j++) {
                lp[i * pr[j]] = pr[j];
            }
        }
    }
};

void testCase() {
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];

    int ans = 1e9;
    map<int, int> divs;
    map<int, vector<int>> cache;
    auto query = [&cache](int n) {
        int T = n;
        vector<int> cur_divs;
        auto it = cache.find(T);
        if (it != cache.end()) {
            cur_divs = it->second;
        } else {
            set<int> s;
            while (lp[T] > 1) {
                s.insert(lp[T]);
                T /= lp[T];
            }
            cur_divs = vector<int>(s.begin(), s.end());
            cache[n] = cur_divs;
        }
        return cur_divs;
    };

    for (int i = 0; i < N; i++) {
        auto cur_divs = query(A[i]);
        for (auto& d : cur_divs) {
            if (divs.count(d)) {
                cout << 0 << endl;
                return;
            } else {
                divs[d] = B[i];
            }
        }
    }

    for (int i = 0; i < N; i++) {
        auto cur_divs = query(A[i]);
        for (auto& d : cur_divs) divs.erase(d);
        auto cur_divs2 = query(A[i] + 1);
        for (auto& d : cur_divs2) {
            if (divs.count(d)) {
                cout << 1 << endl;
                return;
            }
        }
        for (auto& d : cur_divs) divs[d] = B[i];
    }

    cout << 2 << endl;
}

int main() {
    Sieve s;

    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    cout << flush;
    return 0;
}