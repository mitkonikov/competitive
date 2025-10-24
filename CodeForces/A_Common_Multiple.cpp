#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    set<int> S;
    for (int i = 0; i < N; i++) {
        int X;
        cin >> X;
        S.insert(X);
    }
    cout << S.size() << endl;
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