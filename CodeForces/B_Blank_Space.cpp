#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    int longest = 0;
    int current = 0;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if (x == 0) {
            current++;
        } else {
            longest = max(longest, current);
            current = 0;
        }
    }
    longest = max(longest, current);
    cout << longest << endl;
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