#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    N *= 2;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());
    vector<pair<int, int>> points(N / 2);
    for (int i = 0; i < N / 2; i++) {
        points[i] = { A[i], A[N/2+i] };
    }
    ll len = 0;
    for (int i = 0; i < N / 2 - 1; i++) {
        len += abs(points[i].first - points[i+1].first);
        len += abs(points[i].second - points[i+1].second);
    }
    cout << len << endl;
    for (int i = 0; i < N / 2; i++) {
        cout << points[i].first << " " << points[i].second << endl;
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