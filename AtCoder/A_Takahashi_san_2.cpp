#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    string S;
    cin >> S;
    reverse(S.begin(), S.end());
    if (S.substr(0, 3) == "nas") {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}