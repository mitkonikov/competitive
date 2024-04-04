#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    vector<int> frq(2);
    string S;
    cin >> S;
    for (int i = 0; i < S.size(); i++) frq[S[i] - 'A']++;
    cout << (char)('A' + max_element(frq.begin(), frq.end()) - frq.begin()) << endl;
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