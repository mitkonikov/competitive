#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int n, m;
    cin >> n >> m;
    n--;
    m--;
    if ((((n % 2 == 1) && (m % 2 == 0)) || ((n % 2 == 0) && (m % 2 == 1))) && !((n % 2 == 1) && (m % 2 == 1))) {
        cout << "Burenka" << endl;
    } else {
        cout << "Tonya" << endl;
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