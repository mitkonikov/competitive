#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int Q;
    cin >> Q;
    vector<int> A;
    for (int i = 0; i < Q; i++) {
        int t, x;
        cin >> t >> x;
        if (t == 1) {
            A.push_back(x);
        } else {
            cout << A[A.size() - x] << endl;
        }
    }
    return 0;
}