#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    bool ok = true;
    int good = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'o') good++;
        if (S[i] == 'x') ok = false;
    }
    cout << ((ok && (good > 0)) ? "Yes" : "No") << endl;
    return 0;
}