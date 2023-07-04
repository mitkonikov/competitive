#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    vector<int> A(8);
    for (int i = 0; i < 8; i++) cin >> A[i];
    bool ok = is_sorted(A.begin(), A.end());
    for (int i = 0; i < 8; i++) {
        ok &= (A[i] >= 100 && A[i] <= 675 && A[i] % 25 == 0);
    }
    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}