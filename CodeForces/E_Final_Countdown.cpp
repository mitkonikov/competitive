#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    reverse(S.begin(), S.end());
    while (S.back() == '0') {
        S.pop_back();
        N--;
    }
    ll add = 0;
    vector<int> to_add(N);
    for (int i = N - 1; i >= 0; i--) {
        to_add[i] = add;
        add += S[i] - '0';
    }
    add = 0;
    for (int i = 0; i < N; i++) {
        ll all = to_add[i] + (S[i] - '0') + add;
        S[i] = (char)('0' + (all % 10));
        add = all / 10;
    }
    while (add) {
        S.push_back((char)('0' + (add % 10)));
        add /= 10;
    }
    reverse(S.begin(), S.end());
    cout << S << endl;
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