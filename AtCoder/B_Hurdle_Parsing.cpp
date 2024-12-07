#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    string S;
    cin >> S;
    int c = 0;
    for (int i = 1; i < S.size(); i++) {
        if (S[i] == '-') {
            c++;
        } else {
            cout << c << " ";
            c = 0;
        }
    }
    cout << endl;
    return 0;
}