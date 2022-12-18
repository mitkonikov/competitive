#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    int bal = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == '\"') {
            bal ^= 1;
            cout << "\"";
        } else if (S[i] == ',') {
            if (bal) cout << ",";
            else cout << ".";
        } else {
            cout << S[i];
        }
    }
    cout << endl;
    return 0;
}