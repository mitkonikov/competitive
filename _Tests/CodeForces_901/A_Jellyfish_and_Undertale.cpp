#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int A, B, N;
    cin >> A >> B >> N;
    vector<int> V(N);
    for (int i = 0; i < N; i++) cin >> V[i];
    ll timer = B;
    for (int i = 0; i < N; i++) {
        timer += min(A, 1 + V[i]) - 1;
    }
    cout << timer << endl;
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