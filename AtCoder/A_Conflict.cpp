#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N;
    string S, T;
    cin >> N >> S >> T;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'o' && T[i] == 'o') {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}