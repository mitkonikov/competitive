#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    string S;
    cin >> S;
    if (S.substr(0, 3) == "ABC") {
        int id = stoi(S.substr(3));
        if (id >= 1 && id <= 349 && id != 316) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}