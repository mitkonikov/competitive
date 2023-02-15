#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    string S;
    cin >> S;
    for (int i = 0; i < S.size(); i++) {
        cout << (S[i] == '0' ? 1 : 0);
    }
    cout << endl;
    cout << flush;
    return 0;
}