#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    set<string> s;
    for (int i = 0; i < N - 1; i++) {
        s.insert(S.substr(i, 2));
    }
    cout << s.size() << endl;
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