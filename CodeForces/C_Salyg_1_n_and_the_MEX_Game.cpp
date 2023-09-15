#include <bits/stdc++.h>
#define ll long long

using namespace std;

void testCase() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    set<int> not_in;
    set<int> inside;
    for (int i = 0; i < N; i++) inside.insert(A[i]);
    for (int i = 0; i < 2 * N; i++) {
        if (!inside.count(i)) {
            not_in.insert(i);
        }
    }
    while (true) {
        int x = *not_in.begin();
        not_in.erase(not_in.begin());
        cout << x << endl;

        int y;
        cin >> y;
        if (y == -1) {
            break;
        }
        if (y == -2) {
            exit(0);
        }
        
        // y;
        not_in.insert(y);
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