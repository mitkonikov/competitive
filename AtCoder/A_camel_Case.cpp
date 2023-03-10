#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    string S;
    cin >> S;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] >= 'A' && S[i] <= 'Z') {
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}