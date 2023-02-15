#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    set<char> back;
    vector<int> suff(N);
    for (int i = N - 1; i >= 0; i--) {
        back.insert(S[i]);
        suff[i] = back.size();
    }
    set<char> front;
    int ans = 0;
    for (int i = 0; i < N - 1; i++) {
        front.insert(S[i]);
        ans = max(ans, (int)front.size() + suff[i + 1]);
    }
    cout << ans << endl;
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