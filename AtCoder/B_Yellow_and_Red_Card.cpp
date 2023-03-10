#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> yellow(N + 10);
    vector<bool> removed(N, false);
    for (int i = 0; i < Q; i++) {
        int t;
        cin >> t;
        int x;
        cin >> x;
        x--;
        if (t == 1) {
            yellow[x]++;
            if (yellow[x] >= 2) removed[x] = true;
        } else if (t == 2) {
            removed[x] = true;
        } else {
            cout << (removed[x] ? "Yes" : "No") << endl;
        }
    }
    return 0;
}