#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    int frq[10];
    for (int i = 0; i < 10; i++) frq[i] = 0;

    char c;
    for (int i = 0; i < n; i++) {
        cin >> c;
        frq[(c-'0')]++;
    }
    
    for (int i = 0; i < q; i++) {
        int k;
        cin >> k;
        int tmp = k;
        for (int c = 9; c >= 0; c--) {
            if (frq[c] == 0) continue;
            if (frq[c] < tmp) {
                tmp -= frq[c];
            } else {
                cout << c << " ";
                break;
            }
        }
    }

    cout << endl;
    return 0;
}