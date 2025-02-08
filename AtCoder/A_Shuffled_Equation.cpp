#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    vector<int> A(3);
    for (int i = 0; i < 3; i++) {
        cin >> A[i];
    }
    bool ok = false;
    vector<int> order{ 0, 1, 2 };
    do {
        if (A[order[0]] * A[order[1]] == A[order[2]]) {
            ok = true;
        }
    } while (next_permutation(order.begin(), order.end()));
    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}