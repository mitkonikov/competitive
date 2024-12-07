#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N, D;
    cin >> N >> D;
    string S;
    cin >> S;
    for (int i = N - 1; i >= 0; i--) {
        if (S[i] == '@' && D > 0) {
            S[i] = '.';
            D--;
        }
    }
    cout << S << endl;
    return 0;
}