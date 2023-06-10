#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int id_max = 0, id2 = 0, id1 = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] == N) id_max = i;
        if (A[i] == 2) id2 = i;
        if (A[i] == 1) id1 = i;
    }
    auto between = [&](int a, int b, int x) {
        if (a < x && x < b) return true;
        if (b < x && x < a) return true;
        return false;
    };
    if (between(id1, id_max, id2)) {
        cout << id_max + 1 << " " << id2 + 1 << endl;
    } else if (between(id2, id_max, id1)) {
        cout << id_max + 1 << " " << id1 + 1 << endl;
    } else {
        cout << id1 + 1 << " " << id1 + 1 << endl;
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