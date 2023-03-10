#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    string S;
    cin >> S;
    for (int i = 0; i < S.size(); i++) {
        S[i] = S[i] - 'a' + 'A';
    }
    cout << S << endl;
    return 0;
}   