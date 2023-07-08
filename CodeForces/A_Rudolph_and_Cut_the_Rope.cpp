#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    int count = 0;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        count += (a > b);
    }
    cout << count << endl;
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