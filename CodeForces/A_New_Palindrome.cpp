#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    string S;
    cin >> S;
    vector<int> frq(26);
    int count = 0;
    for (int i = 0; i < S.size(); i++) frq[S[i]-'a']++;
    for (int i = 0; i < 26; i++) if (frq[i] >= 2) count++;
    cout << (count >= 2 ? "YES" : "NO") << endl;
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