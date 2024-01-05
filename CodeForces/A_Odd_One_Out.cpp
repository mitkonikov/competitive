#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int A, B, C;
    cin >> A >> B >> C;
    map<int, int> frq;
    frq[A]++;
    frq[B]++;
    frq[C]++;
    for (auto [u, f]: frq) {
        if (f == 1) {
            cout << u << endl;
            return;
        }
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