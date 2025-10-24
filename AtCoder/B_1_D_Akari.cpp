#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    string S;
    cin >> S;
    const int N = S.size();
    if (S == string(N, '.')) {
        cout << 'o' << S.substr(1) << endl;
        return 0;
    }
    bool flip = true;
    for (int i = 0; i < N; i++) {
        if (flip && S[i] == '.') {
            flip = false;
            S[i] = 'o';
        } else if (!flip && S[i] == '#') {
            flip = true;
        }
    }
    cout << S << endl;
    return 0;
}