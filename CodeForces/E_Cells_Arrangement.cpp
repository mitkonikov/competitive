#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    cout << "1 1" << endl;
    cout << "1 2" << endl;
    for (int i = 3; i <= N; i++) {
        cout << i << " " << i << endl;
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