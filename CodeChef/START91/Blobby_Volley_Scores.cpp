#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    int server = 0;
    vector<int> points(2, 0);
    for (int i = 0; i < N; i++) {
        if ((S[i] - 'A') == server) {
            points[server]++;
        } else {
            server ^= 1;
        }
    }
    cout << points[0] << " " << points[1] << endl;
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