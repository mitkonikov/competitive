#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N;
    cin >> N;
    string s;
    cin >> s;
    int cur = 0;
    for (int i = 0; i < N; i++) {
        if (s[i] == '|') cur ^= 1;
        if (s[i] == '*') {
            if (cur) {
                cout << "in" << endl;
            } else {
                cout << "out" << endl;
            }
            return 0;
        }
    }
    cout << "out" << endl;
    return 0;
}