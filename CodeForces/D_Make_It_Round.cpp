#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    ll n, m;
    cin >> n >> m;

    int div[2] = { 0, 0 };
    ll tn = n;
    while (tn % 2 == 0) {
        div[0]++;
        tn /= 2;
    }
    while (tn % 5 == 0) {
        div[1]++;
        tn /= 5;
    }
    
    ll construct = 1;
    int dn[2] = { div[0], div[1] };
    while (true) {
        if (div[0] == div[1]) break;
        if (div[0] < div[1]) {
            if (construct * 2 <= m) {
                construct *= 2;
                div[0]++;
                continue;
            }
        } else {
            if (construct * 5 <= m) {
                construct *= 5;
                div[1]++;
                continue;
            }
        }
        break;
    }

    while (construct * 10 <= m) construct *= 10;
    construct *= m / construct;
    cout << n * construct << endl;
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