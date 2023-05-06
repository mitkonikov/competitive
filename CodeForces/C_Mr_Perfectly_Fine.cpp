#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    vector<pair<int, string>> A(N);
    int time = INT_MAX;
    int t1 = INT_MAX/10;
    int t2 = INT_MAX/10;
    for (int i = 0; i < N; i++) {
        cin >> A[i].first >> A[i].second;
        if (A[i].second == "11") {
            time = min(time, A[i].first);
        } else if (A[i].second == "10") {
            t1 = min(t1, A[i].first);
        } else if (A[i].second == "01") {
            t2 = min(t2, A[i].first);
        }
    }
    time = min(time, t1 + t2);
    if (time >= INT_MAX / 20) {
        cout << -1 << endl;
    } else {
        cout << time << endl;
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