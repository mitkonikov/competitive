#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    vector<string> a = { "ACE", "BDF", "CEG", "DFA", "EGB", "FAC", "GBD" };
    string S;
    cin >> S;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == S) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}   