#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    vector<ll> A(N - 1);
    for (int i = 0; i < N - 1; i++) cin >> A[i];
    map<ll, int> mp;
    mp[A[0]]++;
    for (int i = 1; i < N - 1; i++) {
        mp[A[i] - A[i-1]]++;
    }
    vector<bool> visited(N + 10);
    int failed = 0;
    ll fs = 0;
    for (auto it: mp) {
        if (it.first > N) {
            // this element is a sum of two elements
            failed++;
            fs = it.first;
        } else {
            if (it.second == 1) {
                visited[it.first] = true;
            } else {
                visited[it.first] = true;
                // this element is a sum of two elements
                failed++;
                fs = it.first;
            }
        }
    }

    if (failed > 1) {
        cout << "NO" << endl;
        return;
    }

    int not_visited = 0;
    ll sum = 0;
    for (int i = 1; i <= N; i++) {
        if (visited[i]) continue;
        not_visited++;
        sum += i;
    }

    if (failed == 0 && not_visited == 1) {
        cout << "YES" << endl;
        return;
    }

    if (fs == sum && not_visited == 2) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    cout << flush;
    return 0;
}