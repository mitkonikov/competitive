#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    vector<int> frq(26);
    string S;
    cin >> S;
    for (int i = 0; i < S.size(); i++) frq[S[i] - 'a']++;
    int f = 0;
    for (int i = 0; i < 26; i++) {
        if (frq[i] > frq[f]) {
            f = i;
        }
    }
    cout << (char)('a' + f) << endl;
    return 0;
}