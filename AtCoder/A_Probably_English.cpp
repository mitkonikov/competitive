#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N;
    cin >> N;
    bool ok = false;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        ok |= (s == "and" || s == "not" || s == "that" || s == "the" || s == "you");
    }
    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}