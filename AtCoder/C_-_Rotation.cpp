#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    ll pos = 0;
    for (int i = 0; i < q; i++) {
        int type, x;
        cin >> type >> x;
        if (type == 1) {
            pos += n - x;
        } else if (type == 2) {
            cout << s[(pos + x - 1) % n] << endl;
        }
    }
    cout << flush;
    return 0;
}